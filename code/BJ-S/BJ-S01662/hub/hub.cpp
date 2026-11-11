#include<bits/stdc++.h>
#define int long long
#define add(a,b) e[++idx]=b, ne[idx]=h[a], h[a]=idx
using namespace std;

int c,t,n,k,idx,e[1<<22],ne[1<<22],h[1<<22];

namespace s1{

vector<vector<int>> ch;
int ans,vis[15],vis2[15],dis[15][15];

void dfs(int k,int step,vector<int> &a){
    if(step==k){
        ch.push_back(a);
        return;
    }
    for(int i=a[step]+1;i<=n;i++)
        if(!vis[i])
            vis[i]=1, a[step]=i,
            dfs(k,step+1,a),
            vis[i]=0, a[step]=0;

}

void dfs2(int u,int fa,vector<int>& S){
    vis2[u]=1;
    for(int i=h[u];i;i=ne[i])
        if(find(S.begin(),S.end(),e[i])==S.end()) continue;
        else if(e[i]!=fa) dfs2(e[i],u,S);
}

bool chk(vector<int> S){
    int k=0; memset(vis2,0,sizeof vis2);
    for(auto &u:S) if(!vis2[u]) dfs2(u,0,S), k++;
    return k<=2;
}

void solve1(){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    ch.clear(); ans=1e18;
    for(int i=1,u,v;i<n;i++)
        cin >> u >> v, add(u,v), add(v,u), dis[u][v]=dis[v][u]=1;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(i==j) continue;
        for(int k=1;k<=n;k++){
            if(dis[i][k]>1e18||dis[k][j]>1e18) continue;
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    vector<int> _t(k,0); dfs(k,0,_t);
    for(auto &S:ch){
        if(!chk(S)) continue;
        int cur=0;
        for(int i=1;i<=n;i++){
            int di=1e18;
            for(auto &j:S) di=min(di,dis[i][j]);
            cur=max(cur,di);
        }
        ans=min(ans,cur);
    }
    cout << ans << endl;
}

};

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        memset(h,0,sizeof h), idx=0;
        cin >> n >> k;
        if(n<=10) s1::solve1();
        else s1::solve1();
    }
    return 0;
}
