#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,D;

const int M=5e3+5;
const int N=2e6+5;
int a[N];
int nxt[N];
int pre[N];

int dis[M][M];
int dp[M][M];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int Testnum,T;
	cin>>Testnum>>T;
	while (T--)
	{
		cin>>n>>D;
		for (int i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		if (n==1)
		{
			cout<<0<<"\n";
			continue;
		}
		if (Testnum==11 or Testnum==12)
		{
			D/=(a[2]-a[1]);
			if (D==0 or D==1)
			{
				cout<<0<<"\n";
				continue;
			}
			cout<<max(0*2ll,n-(2*D-1))<<"\n";
			continue;
		}
		int j=1;
		for (int i=1; i<=n; i++)
		{
			while (a[j]<a[i]-D) j++;
			pre[i]=j;
		}
		j=n;
		for (int i=n; i>=1; i--)
		{
			while (a[j]>a[i]+D) j--;
			nxt[i]=j;
		}
		for (int i=1; i<=n; i++)
		{
			int p=nxt[i],cnt=1;
			for (int j=i+1; j<=n; j++)
			{
				if (p<j and cnt!=1e9)
				{
					p=nxt[p];
					cnt++;
				}
				if (nxt[p]<j)
				{
					cnt=1e9;
				}
				dis[i][j]=dis[j][i]=cnt;
			}
		}
		int cnt=0;
		for (int i=1; i<=n; i++) dp[i][i]=1;
		for (int len=2; len<=n; len++)
		{
			for (int i=1; i<=n-len+1; i++)
			{
				int j=i+len-1;
				dp[i][j]=0;
				for (int k=i+1; k<=j; k++)
				{
					if (k>nxt[i]) break;
					if (dis[i][k]+dis[k][j]==dis[i][j])
					{
						dp[i][j]+=dp[k][j];
						dp[i][j]=min(dp[i][j],3*1ll);
						if (dp[i][j]>=3) break;
					}
				}
				if (dp[i][j]==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

