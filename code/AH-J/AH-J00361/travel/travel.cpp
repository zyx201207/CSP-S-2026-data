#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int ua,ub,va,vb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    ua=(ca[0]-'0')*10+(ca[1]-'0');
    va=(cb[0]-'0')*10+(cb[1]-'0');
    if(ua!=va){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    ub=(sa[0]-'0')*10+(sa[1]-'0');
    vb=(sb[0]-'0')*10+(sb[1]-'0');
    if(ub!=vb){
        cout<<"000";
        return 0;
    }
    cout<<1;
    char a=sa[2],b=sb[2];
    if(a=='A'||a=='B'||a=='C'){
        if(b=='A'||b=='B'||b=='C'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else{
        if(b=='D'||b=='F'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }
    if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
