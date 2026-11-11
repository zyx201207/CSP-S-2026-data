#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;

const int MAXN=5e2+5,MAXM=5e5+5,MAXV=2e6+5,MAXQ=1e5+5;
int c,n,m,d,q,tot,W[MAXM],k[MAXN],dis[MAXV],x[MAXQ],y[MAXQ],ans[MAXQ];
int cnt,head[MAXV],nxt[MAXV],to[MAXV],w[MAXV];
bool vis[MAXV];
vector<int>a[MAXN],t[MAXN];
vector<int>qry[MAXM];

void add(int x,int y,int z){
    to[++cnt]=y;
    w[cnt]=z;
    nxt[cnt]=head[x];
    head[x]=cnt;
}
void dijkstra(int s){
    struct node{
        int x,d;
        bool operator>(const node& y)const{
            return d>y.d;
        }
    };
    priority_queue<node,vector<node>,greater<node>>q;
    for(int i=1;i<=n+m;i++)vis[i]=false;
    for(int i=1;i<=n+m;i++)dis[i]=4e18;
    dis[s]=0,q.push({s,0});
    while(!q.empty()){
        int x=q.top().x;
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=nxt[i]){
            int y=to[i],l=w[i];
            if(dis[x]+l<dis[y]){
                dis[y]=dis[x]+l;
                q.push({y,dis[y]});
            }
        }
    }
    for(int id:qry[s])
        ans[id]=dis[y[id]]+W[s]+W[y[id]];
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    tot=m;
    int ks=0;
    for(int i=1;i<=n;i++){
        cin>>k[i],ks+=k[i];
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1,na,nt;j<=k[i];j++){
            cin>>na>>nt;
            a[i][j]=na,t[i][j]=nt;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++)
            add(a[i][j],m+i,t[i][j]),add(m+i,a[i][j],t[i][j]);
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        qry[x[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
        if(!qry[i].empty())dijkstra(i);
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}