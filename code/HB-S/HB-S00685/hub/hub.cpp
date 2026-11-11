#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector<int> g[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int m=n/2;
        if(k==n) cout<<0<<'\n';
        else if(k>=m) cout<<1<<'\n';
        else{
            int ans=(m-k+3)/4+1;
            cout<<ans<<'\n';
        }
    }
    return 0;
}