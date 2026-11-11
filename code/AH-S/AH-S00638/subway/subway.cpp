#include<bits/stdc++.h>
#define int long long
#define piii pair<int,pair<int,int>>
using namespace std;
inline void read(int &x)
{
    x=0;
    char ch=getchar(),f=1;
    while(ch<'0'||ch>'9')f=(ch=='-')?-f:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    x*=f;
}
const int N=5e5+5;
int c,n,m,d,q,w[N][25],vis[N][25],dis[N][25];
vector<int>e[N][25];
struct que{
    int u,v,id,ans;
    bool operator <(que a){
        return u<a.u;
    }
}qu[N];
bool cmp(que a,que b){return a.id<b.id;}
void dij(int s)
{
    for(int i=1;i<=m;i++)for(int j=1;j<=20;j++)dis[i][j]=0x3f3f3f3f3f3f3f3f,vis[i][j]=0;
    priority_queue<piii,vector<piii>,greater<piii>> q;
    for(int i=1;i<=20;i++)
		if(w[s][i])
			q.push({w[s][i],{s,i}});
    while(!q.empty())
    {
        auto p=q.top();q.pop();
        int u=p.second.first,co=p.first,x=p.second.second;
        if(vis[u][x])continue;
        vis[u][x]=1;
        for(int i=0;i<e[u][x].size();i++)
            if(!vis[e[u][x][i]][x]&&dis[e[u][x][i]][x]>co)
            {
                q.push({co,{e[u][x][i],x}});
                dis[e[u][x][i]][x]=co;
			}
        for(int i=1;i<=20;i++)
			if(!vis[u][i]&&w[u][i]&&dis[u][i]>co+w[u][x]+w[u][i])
				q.push({co+w[u][x]+w[u][i],{u,i}}),dis[u][i]=co+w[u][x]+w[u][i];
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;i++)read(w[i][0]);
    for(int i=1,u,v;i<=n;i++)
    {
        int k,co;
        read(k),read(u),read(co);
        k-=1;
        while(k--)
            read(v),e[u][i].push_back(v),e[v][i].push_back(u),w[u][i]=co,u=v,read(co);
        w[u][i]=co;
    }
    for(int i=1;i<=q;i++)
    {
        read(qu[i].u),read(qu[i].v),qu[i].id=i,qu[i].ans=0x3f3f3f3f3f3f3f3f;
        if(qu[i].u>qu[i].v)swap(qu[i].u,qu[i].v);
    }
    sort(qu+1,qu+1+q);
    for(int i=1;i<=q;i++)
    {
        if(qu[i].u!=qu[i-1].u)
            dij(qu[i].u);
        for(int j=1;j<=20;j++)qu[i].ans=min(qu[i].ans,dis[qu[i].v][j]+w[qu[i].v][j]);
        qu[i].ans+=w[qu[i].u][0]+w[qu[i].v][0];
    }
    sort(qu+1,qu+1+q,cmp);
    for(int i=1;i<=q;i++)
        cout<<qu[i].ans<<'\n';
    return 0;
}
