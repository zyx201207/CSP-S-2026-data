#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		int x[2000010];
		int sum[2000010];
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= d;i++)
		{
			sum[i] = 1;
		}
		for(int i = d+1;i <= n;i++)
		{
			for(int j = i-d;j <= i;j++)
			{
				sum[i] += x[j];
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(sum[i] == 2)
			{
				ans++;
			}
		}
		cout << ans << endl; 
	}
	
	return 0;
} 
