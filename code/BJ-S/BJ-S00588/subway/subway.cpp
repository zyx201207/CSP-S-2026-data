#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxm=5e5+10,maxn=5e2+10,maxq=1e5+10;
int c,n,m,d,q,w[maxm],k[maxn],a[maxm],t[maxm],dis[maxm],T;
bool vis[maxm],is[maxm];
vector<pii>adj[maxm];
int read(){
    int x=0ll,f=1ll;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1ll;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10ll+ch-48ll;ch=getchar();}
    return x*f;
}
int dijsktra(int s,int e){
    for(int i=1;i<=m;i++)
        dis[i]=LLONG_MAX,vis[i]=false;
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto e:adj[u]){
            int to=e.first,w=e.second;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                pq.push({dis[to],to});
            }
        }
    }
    return dis[e];
}
int dfs(int now,int End,int ans){
    is[now]=true;
    if(now==End)return ans;
    for(auto v:adj[now]){
        if(is[v.first])continue;
        int a=dfs(v.first,End,ans+1);
        if(a!=-1)return a;
    }
    is[now]=false;
    return -1;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
        w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++)
            a[j]=read(),t[j]=read();
        if(c<=19&&c>=12)T=t[1];
        for(int x=1;x<=k[i];x++){
            for(int y=x+1;y<=k[i];y++){
                adj[a[x]].push_back({a[y],t[x]+t[y]});
                adj[a[y]].push_back({a[x],t[x]+t[y]});
            }
        }
    }
    if(c<=19&&c>=12){
        for(int i=1;i<=q;i++){
            for(int i=1;i<=m;i++)
                is[i]=false;
            int s=read(),e=read(),enumber=dfs(s,e,0);
            cout<<w[s]+w[e]+T*enumber<<'\n';
        }
        return 0;
    }
    for(int i=1;i<=q;i++){
        int s=read(),e=read();
        cout<<dijsktra(s,e)+w[s]+w[e]<<'\n';
    }
    return 0;
}
