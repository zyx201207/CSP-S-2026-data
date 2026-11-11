#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int f[60][220000],sum[220000];
int vis[220000];
int pw[60];
int ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pw[0]=1;
	for (int i=1;i<=30;i++)
		pw[i]=pw[i-1]*2;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int w=0;
		while (x!=0)
		{
			if (x&1)
			{
				f[w][i]=1;
				sum[w]++;
			}
			w++;
			x>>=1;
		}
		vis[i]=1;
	}
	for (int i=30;i>=0;i--)
	{
		if (sum[i]>=m)
		{
			int cnt=0;
			for (int j=1;j<=n;j++)
			{
				cnt+=(vis[j]&f[i][j]);
			}
			if (cnt>=m)
			{
				ans+=pw[i];
				for (int j=1;j<=n;j++)
					vis[j]=(vis[j]&f[i][j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
