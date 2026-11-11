#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	long long ans=a[1];
	if(n==1)
	{
		for (int i = 2; i <= n; i++)
		{
			ans=max(ans,a[i]);
			cin >> ans;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(a[i]<a[i+1])
		{
			int cnt=a[i+1];
			a[i+1]=a[i];
			a[i]=a[i+1];
		}
	}
	for (int i = 2; i <= m; i++)
	{
		ans&=a[i];
	}
	cout << ans;
	return 0;
 } 
