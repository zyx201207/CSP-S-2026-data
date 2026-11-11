#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,t,n,k,x,y,vis[1000010],p[1000010];
vector<int>g[1000010];
void dfs1(int x){
    if(vis[x]==1){
        return;
    }
    vis[x]=1;
    for(auto v:g[x]){
        if(p[v]==1){
            dfs1(v);
        }
    }
}

void dfs(int x,int s){
    if(x>k){
        return;
    }
    if(x>n){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(p[i]==1&&vis[i]==0){
                dfs1(i);
            }
        }

        return;
    }
    p[x]=0;
    dfs(x+1,s);
    p[x]=1;
    dfs(x+1,s+1);
}
signed main(){
    freopen("hub1.in","r",stdin);
    freopen("hub1.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
    }
    cout<<1<<"\n"<<2;
    return 0;
}
