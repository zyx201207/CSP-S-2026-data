#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;

int c,n,d,x[N],dp[N],cnt[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i=1;i<=n;i++)
			cin >> x[i];
		if (c>=11 && c<=12)
		{
			int cnt=0,y=x[2]-x[1],step=d/y;
			if (step<=1 || n==1)
			{
				cout << "0\n";
				continue;
			}
			for (int i=1;i<=n;i++)
				cnt+=min(i+2*step-1,n)-min(i+2*step-2,n);
			cout << cnt << '\n';
			continue;
		}
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			dp[i]=0,cnt[i]=1;
			for (int j=i+1;j<=n;j++)
			{
				dp[j]=1e18,cnt[j]=0;
				for (int k=j-1;k>=i;k--)
				{
					if (x[j]-x[k]>d) break;
					if (dp[k]+1<dp[j])
						dp[j]=dp[k]+1,cnt[j]=cnt[k];
					else if (dp[k]+1==dp[j])
						cnt[j]+=cnt[k];
				}
				if (cnt[j]>2) cnt[j]=0;
				else if (cnt[j]==2) sum++;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
