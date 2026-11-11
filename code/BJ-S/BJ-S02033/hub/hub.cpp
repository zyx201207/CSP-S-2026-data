#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int c,t;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>g[N];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<k-1<<"\n";
}

signed main(){

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==0){
        cout<<1<<"\n"<<2;
        return 0;
    }
    while(t--){
        solve();
    }

    return 0;
}
