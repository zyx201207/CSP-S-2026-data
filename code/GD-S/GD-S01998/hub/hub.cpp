#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok=false;
    vector<int> v;
    auto dfs=[&](auto&& self,int id,int cnt,int x)->void{
        if(cnt==k){
            vector<int> dis(n+1);
            queue<int> q;
            for(int i:v) q.push(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto v:g[u]){
                    if(dis[v]>dis[u]+1){
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
            bool bol=1;
            for(int i=1;i<=n;i++) if(dis[i]>x) bol=0;
            if(bol) ok=1;
        }
        if(id==n+1)return;
        self(self,id+1,cnt,x);
        v.push_back(id);
        self(self,id+1,cnt+1,x);
        v.pop_back();
    };
    auto check=[&](int x)->bool{
        v.clear();
        ok=false;
        dfs(dfs,1,0,x);
        return ok;
    };
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}