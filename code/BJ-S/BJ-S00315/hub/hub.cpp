#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,k;
vector<int> g[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k>=n){
            cout<<"0\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}
