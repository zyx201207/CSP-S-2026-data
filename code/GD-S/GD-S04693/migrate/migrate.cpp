#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000005],ans,f[200005],vis[200005];
vector<int> e[10005];
void bfs(int uu)
{
	queue<int> q;
	while(!q.empty())q.pop();
	memset(vis,0,sizeof vis);
	memset(f,0,sizeof f);
	q.push(uu);
	vis[uu]=1,f[uu]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(f[u]>2)continue;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(vis[v])
			{
				if(vis[v]>vis[u])f[v]+=f[u];
				continue;
			}
			vis[v]=vis[u]+1;
			f[v]=f[u];
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==uu)continue;
		if(f[i]==2)ans++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)
			bfs(i);
		for(int i=1;i<=10000;i++)e[i].clear();
		cout<<ans/2<<"\n";
	}
	return 0;
}
