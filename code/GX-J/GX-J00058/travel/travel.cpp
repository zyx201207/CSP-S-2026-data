#include<bits/stdc++.h>
using namespace std;
string cx1,sw1,cx2,sw2;//chexiang     zuowei
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx1>>sw1>>cx2>>sw2;
    int sw111=sw1[2]-'0'+1,sw22=sw2[2]-'0',sw110=sw1[2]-'0'-1;

    if(cx1==cx2)cout<<1;
    else {
        cout<<"0000";
        return 0;}

    if((sw1[0]==sw2[0])&&(sw1[1]==sw2[1]))cout<<1;
    else {
        cout<<"000";
        return 0;}
    if((sw1[2]<='C'&&sw2[2]<='C')||(sw1[2]>='D'&&sw2[2]>='D')){
        cout<<1;
    }
    else  {
        cout<<"00";
        return 0;}
    if((sw1[2]=='D')||(sw1[2]=='F')||(sw111==sw22)||(sw110==sw22)){
         cout<<1;           }
    else cout<<0;






    return 0;


}

