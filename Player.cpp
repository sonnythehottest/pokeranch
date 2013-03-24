#include "Player.h"
#include <iostream>
using namespace std;

    Player::Player(){
        nama="pemain";
        uang = 1000;
        curX=0;
        curY=0;
        jumlahMenang=0;
        jumlahKalah=0;
        jumlahEscape=0;
        waktu=0; //detik
        warnaPlayer="putih";
    }

    Player::Player(string a){
        nama="a";
        uang = 1000;
        curX=0;
        curY=0;
        jumlahMenang=0;
        jumlahKalah=0;
        jumlahEscape=0;
        waktu=0;
        warnaPlayer="putih";
    }

    Player::~Player(){}

    /*-------------------------------------------------------------------------------------------getter---------------------------------------------------------------------------------------- */
    string Player::getNama(){
        return nama;
    }

    int Player::getUang(){
        return uang;
    }

    int Player::getCurX(){
        return curX;
    }

    int Player::getCurY(){
        return curY;
    }

    int Player::getJumlahMenang(){
        return jumlahMenang;
    }

    int Player::getJumlahKalah(){
        return jumlahKalah;
    }

    int Player::getJumlahEscape(){
        return jumlahEscape;
    }

    int Player::getWaktu(){
        return jumlahEscape;
    }

    string Player::getWarnaPlayer(){
        return warnaPlayer;
    }

	/*-------------------------------------------------------------------------------------------setter---------------------------------------------------------------------------------------- */
	void Player::setNama(string _n){
		this->nama = _n;
	}

	void Player::setUang(int _u){
		this->uang = _u;
	}


/*----------------------------------------------------------------------------------method utama------------------------------------------------------------------------------- */

    void Player::bet(int jmlBet, bool isMenang){
        if (isMenang==true){
            uang=uang+jmlBet;
        }else{
            uang=uang-jmlBet;
        }
    }

//    void Player::battle(string, NPC)
//    void Player::battle(string, Monster);

    void Player::save(string){
        //disimpan dg btk apa?
    }

    void Player::sleep(){
        //nunggu monster
    }

    void Player::sell(Item item, int n){

        for (int ii=0; ii<n;ii++){
            for (int i=0; i< listItem.size(); i++){
                if(listItem.at(i)==item){
                        listItem.erase(listItem.begin()+i);
                        cout << item.getItemName() << " dijual"<< endl;
                        uang=uang + item.getHarga();
                }else if(i==(listItem.size()-1)){
                        cout << "item tidak tersedia" << endl;
                }
            }//end for 2
        }//end for 1
    }

    void Player::buy(Item i){
        if(uang >= i.getHarga()){
            addToListItem(i);
            uang= uang - i.getHarga();
            cout << i.getItemName() << " dibeli" << endl;
        }else{
            cout << "uang tidak cukup" << endl;
        }
    }

    int Player::teleport(int currentState, int xPosition, int yPosition){
    // return state tujuan player                                                                   belum selesai
        if (currentState==0){
            return 1;
        }else if(currentState==1){
            return 2;
        }

    }

    void Player::move(string s, int i, Screen sc){
        if(s=="bawah"){
            if( (curX+i)>sc.getXLength() ){
            curX=sc.getXLength();
            cout << "mentok cuy"<<endl;
            }else {
                curX= curX+i;
            }

        }else if(s=="atas"){
            if( (curX-i)<0){
            curX=0;
            cout << "mentok cuy"<<endl;
            }else {
                curX= curX-i;
            }
        }else if(s=="kiri"){
            if( (curY-i)<0){
            curY=0;
            cout << "mentok cuy"<<endl;
            }else {
                curY= curY-i;
            }
        }else if(s=="kanan"){
            if( (curY+i)>sc.getYLength()){
            curY=sc.getYLength();
            cout << "mentok cuy"<<endl;
            }else {
                curY= curY+i;
            }
        }


    }

    void Player::showMonsterList(){

    }

    void Player::showItemList(){

    }

    void Player::setMonster(string){
        //set default pokemon untuk battle
    }

    void Player::dismiss(string s){
        //menghapus monster bernama s dari listMonster
        listMonster.erase(s);
    }

    void Player::escape(){
////////////////////////////// belum selesai

        jumlahEscape++;
    }

    void Player::change(string s){

    }

    void Player::addMoney(int i){
        uang=uang+i;
    }


/*-------------------------------------------------------------------------------------method baru---------------------------------------------------------------------------------- */
    void Player::addMonster(Monster& _m){
		cout << "method add monster" << endl;
	}

    void Player::delMoney(int i){
        //mengurangi uang sebesar i
        uang = uang - i;
    }

    void Player::delItem(Item item){
        //menghapus item dari listItem
        for(int i=0; i< listItem.size();i++){
            if(listItem.at(i)==item){
                listItem.erase(listItem.begin() + i);
            }//end if
        }//end for

    }



/*--------------------------------------------------------------------------------------method tambahan---------------------------------------------------------------------------------------*/

void Player::printListItem(){
    cout << endl;
    cout << "list item: "<<endl;
    for(int i=0; i<listItem.size();i++){
        Item &a = listItem.at(i);                                   //reference???
        cout << a.getItemName()<<endl;
    }//end for
}

void Player::printListMonster(){
    cout << endl;
    cout << "list monster: "<<endl;
    typedef map<string,Monster>::const_iterator mapIter;
    for(mapIter iter = listMonster.begin(); iter != listMonster.end(); iter++){
        cout << iter->first << endl;
    }//end for
}

void Player::addToListItem(Item item){
        listItem.push_back(item);               //push item ke akhir vector listItem
}

void Player::addToListMonster(string namaMonster, Monster monster){
        listMonster.insert(make_pair(namaMonster, monster));
}
