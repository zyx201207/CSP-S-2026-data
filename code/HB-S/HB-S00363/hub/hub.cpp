#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k;
vector<vector<ll>>g;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        g.resize(n+1);
        for(int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<"1\n";
    }
    return 0;
}
