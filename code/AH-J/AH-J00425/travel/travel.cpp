#include<bits/stdc++.h>
#define int long long
using namespace std;
int solve(char c){
    if(c=='A')return 1;
    if(c=='B')return 2;
    if(c=='C')return 3;
    if(c=='D')return 4;
    if(c=='F')return 5;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    int ee,ff;
    cin>>a>>b>>e>>c>>d>>f;
    ee=solve(e);
    ff=solve(f);
    if(a==c){
        cout<<1;
        if(b==d){
            cout<<1;
            if(ee<=3&&ff<=3||ee>3&&ff>3){
                cout<<1;
                if(ee-ff==1||ee-ff==-1){
                    cout<<1;
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
