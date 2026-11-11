#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int C,T;
int n,k;
int head[N],to[N<<1],nxt[N<<1],cnt;
bool vis[N];
int ans;
int fa[N];
int Find(int x){
    if(x==fa[x])
        return x;
    return fa[x]=Find(fa[x]);
}
void join(int x,int y){
    if(Find(x)!=Find(y))
        fa[fa[x]]=fa[y];
}
void add(int u,int v)
{
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
struct movenode
{
    int u;
    long long d;
    bool operator <(const movenode &b) const
    {
        return d > b.d ;
    }
};
int dis[N];
priority_queue<movenode> q;
void dij()
{
    for(int i=1;i<=n;i++){
        if(vis[i]){
            dis[i]=0;
            q.push((movenode){i,0});
        }
    else
        dis[i]=1e9;
    }
    while(!q.empty()){
        movenode x=q.top();
        q.pop();
        int u=x.u;
        if(dis[u]!=x.d)
            continue;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push((movenode){v,dis[v]});
            }
        }
    }
}
void cleargraph(){
    for(int i=1;i<=n;i++)
        head[i]=0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--){
        ans=1e9;
        cleargraph();
        cin>>n>>k;
        for(int i=1,u,v;i<=n-1;i++){
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        for(int s=1;s<(1<<n);s++){
            int num=0;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    num++;
                }
            }
            if(num!=k){
                continue;
            }
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    vis[i]=true;
                    fa[i]=i;
                }else{
                    vis[i]=false;
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    bool flag=false;
                    for(int j=head[i];j;j=nxt[j]){
                        if(vis[to[j]]){
                            join(to[j],i);
                        }
                    }
                }
            }
            num=0;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1)) && Find(i)==i){
                    num++;
                }
            }
            if(num>2)
                continue;
            dij();
            int res=0;
            for(int i=1;i<=n;i++)
                res=max(res,dis[i]);
       /*     if(res==1){
                for(int i=1;i<=n;i++)
                    cout<<(bool)(s&(1<<(i-1)));
                cout<<endl;
            }*/
            ans=min(ans,res);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
