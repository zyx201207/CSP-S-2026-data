#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int rcr,xcr;
    string rseat,xseat;
    cin >> rcr >> rseat >> xcr >> xseat;
    if(rcr==xcr){
        cout <<1;
    }else{
        cout<<0;
    }
    if(rcr==xcr&&rseat[1]==xseat[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(rcr==xcr&&rseat[1]==xseat[1]){
        if(rseat[2]=='A'||rseat[2]=='B'||rseat[2]=='C'&&xseat[2]=='A'||xseat[2]=='B'||xseat[2]=='C'){
            cout<<1;
            if(int(rseat[2])+1==int(xseat[2])||int(rseat[2])-1==int(xseat[2])){
                cout<<1;
            }else{
                cout<<0;
            }
        }else if(rseat[2]=='D'||rseat[2]=='F'&&xseat[2]=='D'||xseat[2]=='F'){
            cout<<1;
            if(int(rseat[2])+1==int(xseat[2])||int(rseat[2])-1==int(xseat[2])){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0<<0;
        }
    }else{
        cout<<0<<0;
    }
    return 0;
}
