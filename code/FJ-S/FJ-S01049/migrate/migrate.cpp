#include<bits/stdc++.h>
using namespace std;
int f[2010][2010],ans[2010][2010],a[2010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--)
	{
		fill(f[0],f[0]+2010*2010,1000000000);
		fill(ans[0],ans[0]+2010*2010,0);
		int n,d;
		cin>>n>>d;
		vector<int> G[n];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)		
				if(abs(a[i]-a[j])<=d)
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
		for(int i=1;i<=n;i++)
		{
			queue<pair<int,int> > q;
			vector<bool> vis(n,0);
			q.push({i,0});
			vis[i]=1;
			while(!q.empty())
			{
				int u=q.front().first;
				int s=q.front().second; 
				q.pop();
				f[i][u]=min(f[i][u],s);
				for(int v : G[u])
				{
					if(vis[i]==0)
					{
						q.push({v,s+1});
						vis[v]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			queue<pair<int,int> > q;
			vector<bool> vis(n,0);
			q.push({i,0});
			vis[i]=1;
			while(!q.empty())
			{
				
				int u=q.front().first;
				int s=q.front().second; 
				q.pop();
				if(s==f[i][u])
					ans[i][u]++;
				for(int v : G[u])
				{
					if(vis[i]==0)
					{
						q.push({v,s+1});
						vis[v]=1;
					}
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(ans[i][j]==2)
					sum++;
		cout<<sum<<endl;
	}
	return 0;
}

