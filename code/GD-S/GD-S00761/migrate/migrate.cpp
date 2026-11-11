#include <bits/stdc++.h>
using namespace std;
long long x[2000001];
int d[5001], r[5001], sum[5005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, T, n, m;
	scanf("%lld", &c);
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &n);
		scanf("%lld", &m);
		for(int i = 1; i<=n; i++)
		{
			scanf("%lld", &x[i]);
		}
		if(n<=5000)
		{
			int ans = 0;
			for(int i = 1; i<=n; i++)
			{
				for(int j = 1; j<=n; j++)
				{
					d[j]=r[j]=sum[j]=0;
				}
				r[0]=i;
				while(r[0]!=n && x[r[0]+1]-x[i]<=m)
				{
					r[0]++;
					d[r[0]]=1;
				}
				sum[i+1]++, sum[r[0]+1]--;
				for(int j = i+1; j<=n; j++)
				{
					if(!d[j])
					{
						break;
					}
					sum[j]+=sum[j-1];
					if(sum[j]==2)
					{
						ans++;
					}
					if(!r[d[j]])
					{
						r[d[j]]=r[d[j]-1];
					}
					while(r[d[j]]!=n && x[r[d[j]]+1]-x[j]<=m)
					{
						r[d[j]]++;
						d[r[d[j]]]=d[j]+1;
					}
					sum[r[d[j]-1]+1]+=sum[j], sum[r[d[j]]+1]-=sum[j];
				}
			}
			cout << ans << endl;
			continue;
		}
		bool flagA = true;
		for(int i = 1; i<n; i++)
		{
			flagA&=x[i+1]-x[i]==x[2]-x[1];
		}
		if(flagA)
		{
			int now = 1+m/(x[2]-x[1]);
			if(now>n)
			{
				now=n;
			}
			now=2*now-2;
			if(now>n || now<=2)
			{
				cout << 0 << endl;
				continue;
			}
			cout << n-now+1 << endl;
			continue;
		}
		cout << 0 << endl;
	}
	return 0;
}
