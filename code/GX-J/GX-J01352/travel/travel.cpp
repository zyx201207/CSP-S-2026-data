#include<bits/stdc++.h>
using namespace std;
string sc,sr,xc,xr;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>sc>>sr>>xc>>xr;
    if(sc==xc){
        cout<<1;
        if(sr[0]==xr[0]){
            if(sr[1]==xr[1]){
                cout<<1;
                if(sr[2]=='A'&&xr[2]=='B'){
                   cout<<11;
                }
                else if(sr[2]=='B'&&xr[2]=='C'){
                    cout<<11;
                }
                else if(sr[2]=='A'&&xr[2]=='C'){
                    cout<<10;
                }
                else if(sr[2]=='D'&&xr[2]=='F'){
                    cout<<11;
                }
                else cout<<00;
            }
            else cout<<0;
        }
        else cout<<0;
    }
    else
        cout<<0000;
    return 0;
}
