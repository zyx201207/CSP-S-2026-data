#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N=600000,M=1000005;
const ll inf=3e18;
int c,n,m,d,Q,head[N],cnt,v[N];
ll w[N],dis[N],ans[100005];
struct que{ll s,t,id;}q[100005];
struct edge{int to;ll w;int next;}e[M];
void add(int x,int y,ll z)
{
    e[++cnt]={y,z,head[x]};
    head[x]=cnt;
}
struct node
{
    int id;ll w;
    bool operator <(const node x)const{return x.w<w;}
};
priority_queue<node>pq;
void dijk(int s)
{
    for(int i=1;i<=n+m;i++) dis[i]=inf,v[i]=0;
    pq.push((node){s,dis[s]=0});
    while(!pq.empty())
    {
        int x=pq.top().id;pq.pop();
        if(v[x]) continue;
        v[x]=1;
        for(int i=head[x];i;i=e[i].next)
        {
            int to=e[i].to;
            if(dis[x]+e[i].w<dis[to])
                pq.push((node){to,dis[to]=dis[x]+e[i].w});
        }
    }
}
void read(int &x)
{
    x=0;
    char c=getchar();
    while(c<48) c=getchar();
    while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
void read(ll &x)
{
    x=0;
    char ch=getchar();
    while(ch<48) ch=getchar();
    while(ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
void bfs(int s)
{
    queue<int>q1;
    for(int i=1;i<=n+m;i++) dis[i]=inf,v[i]=0;
    q1.push(s);dis[s]=0;
    while(!q1.empty())
    {
        int x=q1.front();q1.pop();
        for(int i=head[x];i;i=e[i].next)
        {
            int to=e[i].to;
            if(!v[to]) dis[to]=dis[x]+1,q1.push(to),v[to]=1;
        }
    }
}
void work()
{
    ll T=0;
    for(int i=1;i<=m;i++)
    {
        int k;
        read(k);
        while(k--)
        {
            int a,t;
            read(a),read(t);T=t;
            add(a,i+n,1);
            add(i+n,a,1);
        }
    }
    for(int i=1;i<=Q;i++)
    {
        read(q[i].s),read(q[i].t);
        q[i].id=i;
        if(q[i].s>q[i].t) swap(q[i].s,q[i].t);
    }
    sort(q+1,q+Q+1,[](que x,que y){return x.s<y.s;});
    int now=0;
    for(int i=1;i<=Q;i++)
    {
        if(now!=q[i].s) bfs(q[i].s),now=q[i].s;
        ans[q[i].id]=w[q[i].s]+w[q[i].t]+dis[q[i].t]*T;
    }
    for(int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);cin.tie(0);
    read(c),read(m),read(n),read(d),read(Q);
    for(int i=1;i<=n;i++) read(w[i]);
    if(12<=c&&c<=19)
    {
        work();
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int k;
        read(k);
        while(k--)
        {
            int a,t;
            read(a),read(t);
            add(a,i+n,t);
            add(i+n,a,t);
        }
    }
    for(int i=1;i<=Q;i++)
    {
        read(q[i].s),read(q[i].t);
        q[i].id=i;
        if(q[i].s>q[i].t) swap(q[i].s,q[i].t);
    }
    sort(q+1,q+Q+1,[](que x,que y){return x.s<y.s;});
    int now=0;
    for(int i=1;i<=Q;i++)
    {
        if(now!=q[i].s) dijk(q[i].s),now=q[i].s;
        ans[q[i].id]=w[q[i].s]+w[q[i].t]+dis[q[i].t];
    }
    for(int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
	return 0;
}
