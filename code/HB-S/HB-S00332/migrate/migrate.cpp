#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,c,t,dist[305][305],book[305],k[305][305],x[305],ans;
vector <int> e[305];
void spfa(int st)
{
	queue <int> q;
	memset(book,0,sizeof book);
	book[st]=1;
	dist[st][st]=0;
	k[st][st]=1;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		book[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(dist[st][v]==dist[st][u]+1)
				k[st][v]+=k[st][u];
			if(dist[st][v]>dist[st][u]+1)
			{
				dist[st][v]=dist[st][u]+1;
				k[st][v]=k[st][u];
				if(book[v]==0)
				{
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		memset(dist,0x3f,sizeof dist);
		memset(k,0,sizeof k);
		ans=0;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=1;j<i;j++)
				if(x[i]-x[j]<=d)
					e[j].push_back(i);
		}
		for(int i=1;i<=n;i++)
			spfa(i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(k[i][j]==2)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
