#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define INF 0x3f3f3f3f3f3f3f3f
ll n,m,d,a[MAXN],dist1[505][505],dist2[505][505],fa[505],cnt;
struct node{
    ll u,v,w;
};
bool cmp(node aa,node bb){
    return aa.w<bb.w;
}
vector<node> p[MAXN],e;
int find(int x){
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int dx=find(x),dy=find(y);
    if(dx!=dy){
        fa[dx]=dy;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    memset(dist1,0x3f,sizeof(dist1));
    memset(dist2,0x3f,sizeof(dist2));
    for(int i=0;i<504;i++){
        dist1[i][i]=0;
        dist2[i][i]=0;
        fa[i]=i;
    }
    int ID,q;
    cin>>ID>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    //
    for(int i=1;i<=n;i++){
        int k,u,w;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>u>>w;
            p[u].push_back({u,i,w});
        }
    }
    //建图
    for(int i=1;i<=m;i++){
        for(int j=0;j<p[i].size();j++){
            for(int k=0;k<p[i].size();k++){
                dist1[p[i][j].v][p[i][k].v]=min(dist1[p[i][j].v][p[i][k].v],p[i][j].w+p[i][k].w);
                dist1[p[i][k].v][p[i][j].v]=dist1[p[i][j].v][p[i][k].v];
            }
        }
    }
    //最段路
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist1[i][j]=min(dist1[i][j],dist1[i][k]+dist1[k][j]);
            }
        }
    }
    //建图
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist1[i][j]<INF){
                e.push_back({i,j,dist1[i][j]});
                cnt++;
            }
        }
    }
    //e上最小生成树
    sort(e.begin(),e.end(),cmp);int cntt=0;
    for(int i=0;i<cnt;i++){
        if(find(e[i].u)!=find(e[i].v)){
            merge(e[i].u,e[i].v);
            dist2[e[i].u][e[i].v]=e[i].w;
            dist2[e[i].v][e[i].u]=e[i].w;
            cntt++;
        }
        if(cntt==n-1) break;
    }
    //最小生成树上的最短路
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
            }
        }
    }
    //查询
    while(q--){
        ll x,y,ans=INF;
        cin>>x>>y;
        for(int i=0;i<p[x].size();i++){
            for(int j=0;j<p[y].size();j++){
                ans=min(ans,dist2[p[x][i].v][p[y][j].v]+a[x]+a[y]+p[x][i].w+p[y][j].w);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}