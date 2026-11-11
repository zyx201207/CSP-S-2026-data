#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll n,k,c,t,u,v,a[N],a2[N],mi=INT_MAX,quan[N];
vector<int> g[N];
int ban()
{
	int ma=INT_MIN;
	queue<int> q;
	int u=0;
	for(int i=1;i<=n;i++) if(a[i]) q.push(i);
	for(int head=1,tail=1;head<=tail;head++)
	{
		u=q.front();
		for(int i=0;i<g[u].size();i++)
		{
			if(quan[u]+1<quan[g[u][i]])
			{
				quan[g[u][i]]=quan[u]+1;
				q.push(g[u][i]);
				tail++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,int(quan[i]));
	}
	return ma;
}
void bfs()
{
	queue<int> q;
	int u=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]) u=i;
		break;
	}
	q.push(u);
	a[u]=0;
	for(int head=1,tail=1;head<=tail;head++)
	{
		u=q.front();
		for(int i=0;i<g[u].size();i++)
		{
			if(a[g[u][i]])
			{
				q.push(g[u][i]);
				a[g[u][i]]=0;
				tail++;
			}
		}
	}
}
void dfs(int i,int n)
{
	if(i-1==n)
	{
		for(int i=1;i<=n;i++) a2[i]=a[i];
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		if(cnt!=k) return;
		cnt=0;
		while(1)
		{
			bool f=0;
			for(int j=1;j<=n;j++)
				if(a[j]==1) f=1;
			if(!f) return;
			else
			{
				cnt++;
				bfs();
			}
		}
		for(int i=1;i<=n;i++) a[i]=a2[i];
		if(cnt<=2) mi=min(int(mi),ban());
	}
	dfs(i+1,n);
	a[i]=1;
	dfs(i+1,n);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
