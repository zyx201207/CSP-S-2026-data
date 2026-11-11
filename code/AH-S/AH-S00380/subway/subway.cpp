#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=505,M=5e5+5;
struct Node {
    LL id,t;
};
LL w[M],k[N],cnt[M];
vector<LL>a[N],t[N];
vector<Node>s1,t1;
LL G[N][N],ans[N][N];
bool vis[N];
LL dis[N];
LL c,n,m,d,q;
LL djs(LL u,LL t){
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    dis[u]=0;
    for(LL i=1;i<=n;i++){
        LL minn=0x3f3f3f3f3f3f3f3f,v;
        for(LL j=1;j<=n;j++){
            if(dis[j]<minn&&!vis[j]){
                minn=dis[j];
                v=j;
            }
        }
        vis[v]=true;
        for(LL j=1;j<=n;j++){
            if(dis[v]+G[v][j]<dis[j]&&!vis[j]){
                dis[j]=dis[v]+G[v][j];
            }
        }
    }
    return dis[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(G,0x3f,sizeof G);
    cin>>c>>n>>m>>d>>q;
    for(LL i=1;i<=m;i++){
        cin>>w[i];
    }
    for(LL i=1;i<=n;i++){
        cin>>k[i];
        LL ac,tc;
        for(LL j=1;j<=k[i];j++){
            cin>>ac>>tc;
            a[i].push_back(ac);
            t[i].push_back(tc);
        }
    }
    for(LL u=1;u<=n;u++){
        for(LL v=u+1;v<=n;v++){
            memset(cnt,0,sizeof cnt);
            for(LL i=0;i<k[u];i++){
                cnt[a[u][i]]=i;
            }
            for(LL j=0;j<k[v];j++){
                if(cnt[a[v][j]]!=0){
                    G[u][v]=min(G[u][v],t[v][j]+t[u][cnt[a[v][j]]]);
                    G[v][u]=min(G[v][u],t[v][j]+t[u][cnt[a[v][j]]]);
                }
            }
        }
    }
    for(LL u=1;u<=n;u++){
        for(LL v=1;v<=n;v++){
            ans[u][v]=djs(u,v);
        }
    }
    LL l,r;
    while(q--){
        cin>>l>>r;
        s1.clear();
        t1.clear();
        for(LL i=1;i<=n;i++){
            for(LL j=0;j<k[i];j++){
                if(a[i][j]==l){
                    s1.push_back({i,j});
                }
                if(a[i][j]==r){
                    t1.push_back({i,j});
                }
            }
        }
        LL minn=0x3f3f3f3f3f3f3f3f;
        for(LL i=0;i<s1.size();i++){
            for(LL j=0;j<t1.size();j++){
                minn=min(minn,t[s1[i].id][s1[i].t]+t[t1[j].id][t1[j].t]+ans[s1[i].id][t1[j].id]);
            }
        }
        cout<<minn+w[l]+w[r]<<endl;
    }
    return 0;
}

