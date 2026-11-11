#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        if(a2.substr(0,2)==b2.substr(0,2)){
            cout<<1;
            int adx,bdx;
            if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')adx=0;
            else adx=1;
            if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')bdx=0;
            else bdx=1;
            if(adx==bdx){
                cout<<1;
                if(adx==1||a2[2]=='B'||b2[2]=='B')cout<<1;
                else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}