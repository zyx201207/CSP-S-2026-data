#include<bits/stdc++.h>
using namespace std;
string s;
char seata2,seatb2;
long long chea,cheb,seata,seatb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    chea=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    seata=(s[0]-'0')*10+(s[1]-'0');
    seata2=s[2];
    cin>>s;
    cheb=(s[0]-'0')*10+(s[1]-'0');
    cin>>s;
    seatb=(s[0]-'0')*10+(s[1]-'0');
    seatb2=s[2];
    if(chea!=cheb){
        cout<<"0000";
    }else if(seata!=seatb){
        cout<<"1000";
    }else if(!((seatb2>='A'&&seatb2<='C'&&seata2>='A'&&seata2<='C')||
              (seatb2=='D'&&seata2=='F')||(seata2=='D'&&seatb2=='F'))){
        cout<<"1100";
    }else if(!(abs(seata2-seatb2)==1||(seatb2=='D'&&seata2=='F')||(seata2=='D'&&seatb2=='F'))){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
