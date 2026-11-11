
#include<bits/stdc++.h>
using namespace std;

using LL=long long ;
const int MAXN=7e5+10;

int c,n,m,d,qs;
int w[MAXN];

int head[MAXN],cnt;;
struct E{int next,to;LL w;}G[(int)5e6];
void add(int u,int v,LL w){
    G[++cnt]={head[u],v,w};
    head[u]=cnt;
}
int st;

LL dis[MAXN];
bool vis[MAXN];
struct node{
    int s;
    LL dis;
    bool operator<(const node & b)const{
        return dis>b.dis;
    }
};
priority_queue<node> q;

void dij(int s){
    for(int i=1;i<=st;++i){
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
        node u=q.top();q.pop();
        if(vis[u.s])continue;
        vis[u.s]=1;
        for(int i=head[u.s];i;i=G[i].next){
            int v=G[i].to;
            if(dis[v]>dis[u.s]+G[i].w){
                dis[v]=dis[u.s]+G[i].w;
                q.push({v,dis[v]});
            }
        }
    }
}

struct que{
    int x,y,id;
    bool operator<(const que& b)const {
        return (x!=b.x?x<b.x:y<b.y);
    }
}ques[(int)1e5+10];

LL ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>qs;

    for(int i=1;i<=m;++i){
        cin>>w[i];
        add(i,i+m,w[i]);
        add(i+m,i,w[i]);
    }
    st=m*2;
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        st++;
        for(int j=1,u,v;j<=k;++j){
            cin>>u>>v;
            add(st,u+m,v);
            add(u+m,st,v);
        }
    }
    for(int i=1;i<=qs;++i){
        cin>>ques[i].x>>ques[i].y;
        ques[i].id=i;
    }
    sort(ques+1,ques+qs+1);

    for(int i=1;i<=qs;++i){
        if(ques[i].x!=ques[i-1].x)dij(ques[i].x);
        ans[ques[i].id]=dis[ques[i].y];
    }
    for(int i=1;i<=qs;++i)
        cout<<ans[i]<<'\n';

    return 0;
}
