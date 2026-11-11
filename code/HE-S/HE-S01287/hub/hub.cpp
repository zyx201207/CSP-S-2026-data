#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
vector<int> g[N];
int dep[N];
int n;


void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    for(auto v : g[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
}

void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    sort(dep+1,dep+n+1);
    cout<<dep[n/2]<<'\n';
}

int main() {
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) sol();
    return 0;
}