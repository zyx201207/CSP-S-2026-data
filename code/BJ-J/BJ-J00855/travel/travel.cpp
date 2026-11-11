#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=0,mod=1e9+7,INF=1e18;
bool get(char a,char b){
    if(a<='C'&&b<='C')return 1;
    if(a>'C'&&b>'C')return 1;
    return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<"1";
        if(a2.substr(0,2)==b2.substr(0,2)){
            cout<<1;
            if(get(a2[2],b2[2])){
                cout<<1;
                if(a2[2]+1==b2[2]||a2[2]-1==b2[2]){
                    cout<<1;
                }else cout<<0;
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
