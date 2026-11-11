#include<bits/stdc++.h>
using namespace std;
int ca,cb;
string sa,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    int checa=sa[0]-'0';
    checa*=10;
    checa+=sa[1]-'0';
    int checb=sb[0]-'0';
    checb*=10;
    checb+=sb[1]-'0';
    char aa=sa[2],bb=sb[2];
    if(ca==cb){
            cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(checa==checb){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(aa>='A'&&aa<='C'&&bb>='A'&&bb<='C'){
        cout<<1;
    }else if(aa>='D'&&aa<='F'&&aa!='E'&&bb>='D'&&bb<='F'&&bb!='E'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(aa-bb)==1){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    return 0;
}
//Trick||Treat!
