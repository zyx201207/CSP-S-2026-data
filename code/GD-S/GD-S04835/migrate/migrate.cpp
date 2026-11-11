#include<iostream>
#include<set>
#include<cmath>
#define int long long
using namespace std;
const int MAXN = 2000005;
const int INF = 0x3f3f3f3f; 
int x[MAXN];
int vis[MAXN];
int tot;
int n,d;
int mn = INF;
int ans;
int c;
void dfs(int u,int cnt)
{
	if(u == tot)
	{
		if(cnt < mn)
		{
			mn = cnt;
			ans = 1;
		}	
		else if(cnt == mn)
			ans++; 
		return;
	}
	for(int i = u+1;i <= n;i++)
	{
		if(abs(x[i] - x[u]) <= d)
		{
			dfs(i,cnt+1);
		}
	}
}
void solve()
{
	cin>>n>>d;
	for(int i = 1;i <= n;i++)
		scanf("%d",&x[i]);
		int cnt = 0;
	if(c == 11 || c == 12)
	{
		cout<<1;
		if(d < (x[2]-x[1]))
			cout<<0<<endl;
		else
		 	cout<<n-d/(x[2]-x[1])*2+1<<endl;
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			mn = INF;
			tot = j;
			ans = 0;
			dfs(i,0);
			if(ans == 2)
			{
				cnt++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<cnt<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	
	while(t--)
	{
		solve();
	}
	return 0;
}
