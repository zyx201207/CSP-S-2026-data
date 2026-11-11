#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
int n,k;
int c,T;
vector<int>e[N];
bool ok[N];
int fa[N];
int dis[N][N];
int ans = 1e9;
int find(int x){
    if(x!=fa[x])fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int u,int v){
    int ru = find(u);
    int rv = find(v);
    if(ru==rv)return;
    fa[ru] = rv;
}
void dfs(int step){
    if(step==n+1){
        int num = 0;
        for(int i = 1;i<=n;i++)if(ok[i])num++;
        if(num!=k)return;
        for(int i = 1;i<=n;i++)fa[i] = i;
        for(int i = 1;i<=n;i++){
            if(!ok[i])continue;
            for(auto v:e[i]){
                if(!ok[v])continue;
                merge(i,v);
            }
        }
        num = 0;
        for(int i = 1;i<=n;i++){
            if(!ok[i])continue;
            if(find(i)==i)num++;
        }
        if(num>2)return;
        num = 0;
        for(int i = 1;i<=n;i++){
            int tmp = 1e9;
            for(int j = 1;j<=n;j++){
                if(ok[j])tmp = min(tmp,dis[i][j]);
            }
            num = max(num,tmp);
        }
        ans = min(ans,num);
        return;
    }
    ok[step] = 1;
    dfs(step+1);
    ok[step] = 0;
    dfs(step+1);
}
void dfs1(int u,int fa,int rt,int num){
    dis[rt][u] = num;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs1(v,u,rt,num+1);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans = 1e9;
        cin>>n>>k;
        for(int i = 1;i<=n;i++)e[i].clear();
        memset(ok,0,sizeof(ok));
        for(int i = 1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i = 1;i<=n;i++)dfs1(i,0,i,0);
        dfs(1);
        cout<<ans<<"\n";
    }



    return 0;
}