#include <bits/stdc++.h>

using namespace std;
#define vec vector
#define For(n) for(int i=0;i<n;++i)

int n;

bool in(int x,vec<int> v){
    return (find(v.begin(),v.end(),x)!=v.end());
}

bool connect(vec<vec<int>> adj,vec<int> build){
    int e = build.back();
    build.pop_back();
    queue<int> q;
    q.push(e);
    vec<int> visited;
    visited.push_back(e);
    while (!q.empty())
    {
        int cx = q.front();
        q.pop();
        for(auto nx : adj[cx]){
            if(in(nx,build)) if(!in(nx,visited)){
                visited.push_back(nx);
                q.push(nx);
            }
        }
    }
    for(auto x:build){
        if(!in(x,visited)){
            return false;
        }
    }
    return true;
}

int solve(){
    int k;
    cin>>n>>k;
    vec<vec<int>> adj;
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto f1 = freopen("hub.in","r",stdin);
    auto f2 = freopen("hub.out","w",stdout);

    int c,t;
    cin>>c>>t;

    while (t--)
    {
        solve();
    }
    

    return 0;
}