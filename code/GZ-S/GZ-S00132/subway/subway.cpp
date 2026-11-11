//GZ-S00132 贵阳市第一中学 李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=5e5+10;
struct Node{
	int to,ne,w;
}e[N];
int c,n,m,d,Q,a[M],dis[N],tot,head[N];
void add(int u,int v,int w)
{
	++tot;
	e[tot].to=v;
	e[tot].w=w;
	e[tot].ne=head[u];
	head[u]=tot;
	return ;
}
void dij(int s)
{
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second,du=q.top().first;
		q.pop();
		if(du>dis[u])
			continue;
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int lst=0;
		for(int j=1;j<=k;j++)
		{
			int id,x;
			cin>>id>>x;
			if(j==1)
				lst=id+m*i;
			else
			{
				add(lst,id+m*i,0);
				add(id+m*i,lst,0);
			}
			add(id,id+m*i,x);
			add(id+m*i,id,x);
		}
	}
	while(Q--)
	{
		int S,T;
		cin>>S>>T;
		dij(S);
		cout<<a[S]+dis[T]+a[T]<<endl;
	}
	return 0;
}
