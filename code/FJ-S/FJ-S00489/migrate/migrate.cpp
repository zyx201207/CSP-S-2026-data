#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=5e3+10,inf=0x3f3f3f3f3f3f3f3f;
int c,tt;
int n,d;
int x[N];
int dist[M][M],f[M][M];
bool st[M][M];
void bfs(int k)
{
	for(int i=1;i<=n;i++)
	{
		dist[k][i]=inf;
	}
	queue<int> q;
	q.push(k);
	dist[k][k]=0;
	f[k][k]=1;
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(f[k][i]==-1)
			{
				continue;
			}
			if(abs(x[t]-x[i])<=d)
			{
				if(dist[k][i]>dist[k][t]+1)
				{
					dist[k][i]=dist[k][t]+1;
					if(f[k][i]+f[k][t]>2)
					{
						f[k][i]=-1;
						continue;
					}
					else
					{
						f[k][i]+=f[k][t];
					}
					q.push(i);
				}
				else
				{
					if(dist[k][i]==dist[k][t]+1)
					{
						if(f[k][i]+f[k][t]>2)
						{
							f[k][i]=-1;
							continue;
						}
						else
						{
							f[k][i]+=f[k][t];
						}
					}
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
	cout.tie(0); 
	cin>>c>>tt;
	while(tt--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				st[i][j]=f[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j||st[i][j]||f[i][j]!=2)
				{
					continue;
				}
				st[i][j]=st[j][i]=1;
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
