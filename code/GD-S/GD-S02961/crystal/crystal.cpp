#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, ans=0;
	cin >> n >> m;
	int a[n+10] = {};
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(n <= 5000)
	{
		for(int i=1;i<=n;i++)
	    {
			for(int j=1;j<=i;j++)
			{
				int sum=0;
				for(int k=j;k<=i;k++)
				{
					sum += a[i]-a[k];
				}
				if(sum <= m)
				{
					ans = max(ans, i-j+1);
				}
			}
		}
		cout << ans;
		return 0;
	}
	int x = a[3] - a[2];
	int  sum = 0;
	while(sum <= m)
	{
		ans++;
		sum += ans*x;
	}
	cout << ans;
	return 0;
}
