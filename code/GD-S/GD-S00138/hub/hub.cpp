#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[1000010];
int n,k;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<(n-2)/3<<endl;
    }
    return 0;
}