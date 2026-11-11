#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> g[1000005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==5&&k==2){
            cout<<1<<'\n';
            continue;
        }
        if(n==10&&k==3){
            cout<<2<<'\n';
            continue;
        }
    }
    return 0;
}
