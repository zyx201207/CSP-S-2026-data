#include<bits/stdc++.h>
#define int long long
#define pll pair<int,int>
using namespace std;
int rd(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
void wrt(int x){
	if(x<10){
	putchar(x+'0');return ;}
	wrt(x/10);putchar(x%10+'0');
}
const int N=5e5+10;
struct node
{
	int v,w;
};
vector<node> e[N];
int c,n,m,d,q,w[N],a[N],t[N],dis[N],vis[N];
void dij(int s)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pll,vector<pll> ,greater<pll> > pq;
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty()) 
	{
		auto u=pq.top();
		pq.pop();
		if(vis[u.second])continue;
		vis[u.second]=1;
		for(auto i:e[u.second])
		{
			int v=i.v,w=i.w;
			if(dis[v]>dis[u.second]+w)
			{
				dis[v]=dis[u.second]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
//	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		w[i]=rd();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int z=j+1;z<=k;z++)
			{
				e[a[j]].push_back({a[z],t[z]+t[j]});
				e[a[z]].push_back({a[j],t[z]+t[j]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		dij(x);
		wrt(dis[y]+w[x]+w[y]),putchar('\n');
	}
	return 0;
}
