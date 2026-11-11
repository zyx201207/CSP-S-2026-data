#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int n,k;
bool cs[N];//is chosen?
bool flag[N];
int f[N][25];
int dep[N],ans;
vector<int> g[N];
void init(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for (int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for (int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (v==fa) continue;
        init(v,u);
    }
}
int getdis(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int res=0;
    for (int i=20;i>=0;i--){
        if (dep[f[u][i]]>=dep[v]){
            res+=(1<<i);
            u=f[u][i];
        }
    }
    if (u==v) return res;
    for (int i=20;i>=0;i--){
        if (f[u][i]!=f[v][i]){
            res+=2*(1<<i);
            u=f[u][i];
            v=f[v][i];
        }
    }
    return res+2;
}
void paint(int u){
    flag[u]=1;
    for (int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (!cs[v]) continue;
        if (flag[v]) continue;
        paint(v);
    }
}
int csd[N],csn[N];//chosen/not chosen
int cur1,cur2;
void dfs(int pl,int cnt){
    if (n-pl+1+cnt<k) return;
    if (cnt>k) return;
    if (pl>n){
        if (cnt!=k) return;
        memset(flag,0,sizeof flag);
        int res=0;
        for (int i=1;i<=n;i++){
            if (!flag[i]&&cs[i]){
                res++;
                paint(i);
            }
        }
        if (res>2) return;
        res=0;
        for (int i=1;i<=cur2;i++){
            int tem=2e9;
            for (int j=1;j<=cur1;j++){
                tem=min(tem,getdis(csn[i],csd[j]));
            }
            res=max(res,tem);
        }
        ans=min(ans,res);
        return;
    }
    //not choose
    csn[++cur2]=pl;
    dfs(pl+1,cnt);
    cur2--;
    //choose
    csd[++cur1]=pl;
    cs[pl]=1;
    dfs(pl+1,cnt+1);
    cs[pl]=0;
    cur1--;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,q;
    cin>>c>>q;
    while (q--){
        for (int i=1;i<=n;i++) g[i].clear();
        memset(cs,0,sizeof cs);
        //memset(f,0,sizeof f);
        //memset(dep,0,sizeof dep);
        cin>>n>>k;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        init(1,0);
        cur1=cur2=0;
        ans=2e9;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
