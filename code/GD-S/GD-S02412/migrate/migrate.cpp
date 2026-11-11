#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		long long dp[200005],ans;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				if(abs(a[i]-a[j]) <= d)
					dp[j]++; 
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(dp[i] == 2)
				ans++;
		}
		cout << (ans-1) << endl;
	}
	return 0;
}
