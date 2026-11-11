#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ax,bx;
    string az,bz;
    cin>>ax>>az>>bx>>bz;
    if(ax==bx){
        cout<<1;
        if(((az[0]-48)*10+(az[1]-48)*10)==((bz[0]-48)*10+(bz[1]-48)*10)){
            cout<<1;
            if((az[2]=='A'||az[2]=='B'||az[2]=='C')&&(bz[2]=='A'||bz[2]=='B'||bz[2]=='C')){
                cout<<1;
                if((az[2]+1==bz[2])||(az[2]-1==bz[2]))cout<<1;
                else cout<<0;
            }else if((az[2]=='D'&&bz[2]=='F')||(bz[2]=='D'&&az[2]=='F')){
                cout<<"11";
            }else cout<<"00";
        }else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
