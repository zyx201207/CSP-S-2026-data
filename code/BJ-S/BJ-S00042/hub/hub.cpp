#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
vector<int>eg[MAXN];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        eg[u].push_back(v);
        eg[v].push_back(u);
    }
    cout<<((n+1)/2+2-k+3)/4<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
