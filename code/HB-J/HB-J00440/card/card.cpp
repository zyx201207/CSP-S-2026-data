#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
//CJwangze bao you wo ceng 20 fen;
void solve(){
    cin>>n>>m;
    while(m--){
        cout<<rand()%n+1;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
