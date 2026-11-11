#include<bits/stdc++.h>
using namespace std;
#define cmin(x, y) x=min(x, y)
int c, T, n, k, d[4005], D[4005], pre[4005][4005], dep[4005], tot;
vector<int>g[4005];
void init(int x, int fa){d[x]=0;for(int i:g[x])if(i!=fa)D[i]=D[x]+1, init(i, x), d[x]=max(d[x], d[i]+1);}
void dfs(int x, int fa, int md){
    dep[x]=0;for(int i:g[x])if(i!=fa)dfs(i, x, md), dep[x]=max(dep[x], dep[i]+1);
    if(dep[x]>=md)tot++;
}
void sol(int x, int fa, int rt, int md, int nw){
    cmin(pre[nw][D[x]], tot+(dep[x]<md));int mx=0, smx=0;
    for(int i:g[x]){
        if(i==rt)continue;
        if(mx<dep[i]+1)smx=mx, mx=dep[i]+1;
        else if(smx<dep[i]+1)smx=dep[i]+1;
    }for(int i:g[x])if(i!=fa){
        int A=dep[i], B=dep[x], L=tot;if(A>=md)tot--;if(B>=md)tot--;
        int tp=dep[i]+1==mx?smx:mx;
        dep[i]=max(dep[i], dep[x]+1);dep[x]=tp;
        if(dep[i]>=md)tot++;if(dep[x]>=md)tot++;
        sol(i, x, rt, md, nw);tot=L;dep[x]=B;dep[i]=A;
    }
}
bool chk(int x){
    for(int i=1; i<=n; i++){
        D[i]=0;init(i, 0);int mx=0, smx=0, tmx=0;
        for(int j:g[i]){
            tot=0;dfs(j, i, x);sol(j, i, i, x, j);
            for(int p=1; p<=n; p++)cmin(pre[j][p], pre[j][p-1]);
            if(d[j]+1>mx)tmx=smx, smx=mx, mx=d[j]+1;
            else if(d[j]+1>smx)tmx=smx, smx=d[j]+1;else if(d[j]+1>tmx)tmx=d[j]+1;
        }for(int j:g[i]){
            int Mx=d[j]+1==mx?smx:mx;
            if(Mx<=x&&pre[j][x-Mx]<=k)return 1;
            for(int t:g[i])if(j!=t){
                int fr=d[j]+1, sc=d[t]+1;if(fr<sc)swap(fr, sc);
                Mx=fr==mx?(sc==smx?tmx:smx):mx;
                if(Mx<=x&&pre[j][x-Mx]+pre[t][n]<=k)return 1;
            }
        }for(int j:g[i])for(int t=0; t<=n; t++)pre[j][t]=1e8;
    }return 0;
}
int solve(){
    if(n==k)return 0;int l=1, r=n, bt=1;
    while(l<=r){
        int md=(l+r)/2;
        if(chk(md))r=md-1, bt=md;
        else l=md+1;
        for(int i=1; i<=n; i++)for(int j=0; j<=n; j++)pre[i][j]=1e8;
    }
    return bt;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(pre, 63, sizeof(pre));
    cin >> c >> T;
    while(T--){
        cin >> n >> k;
        for(int i=1; i<n; i++){
            int u, v;cin >> u >> v;
            g[u].push_back(v);g[v].push_back(u);
        }cout << solve() << '\n';
        for(int i=1; i<=n; i++)g[i].clear();
    }
    return 0;
}