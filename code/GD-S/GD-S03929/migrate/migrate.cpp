#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+10;
int n,m,c,t,d;
int x[N];
int ans[N],sum[N];

void dfs(int u,int cur)
{
	if(cur<sum[u])
	{
		sum[u] = cur;
		ans[u] = 1;
	}
	else if(cur == sum[u])
	{
		ans[u]++;
	}
	if(u == n)
	{
		return ;
	}
	int v = u+1;
	while(x[v]-x[u]<=d && v<=n)
	{
		dfs(v,cur+1);
		v++;
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			cin>>x[i];
			
		}
		int cnt =0;
		for(int i=1; i<=n; i++)
		{
			
			for(int j=1; j<=n; j++)
			{
				sum[i] = 1e9;
				ans[i] = 0;
			}
			dfs(1,0);
			
			for(int i=1; i<=n; i++)
			{
				if(ans[i] == 2)
				{
					cnt++;
//					cout<<i<<' ';
				}
			}
			
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
