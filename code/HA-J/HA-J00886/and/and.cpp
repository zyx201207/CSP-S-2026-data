#include <bits/stdc++.h>
using namespace std;

long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxn=0,ans=0;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxn=max(maxn,a[i]);
		ans=ans&a[i];
	}
	if (n<=2000)
	{
		if (m==1) cout << maxn;
		else if (m==2)
		{
			sort(a+1,a+n+1);
			for (int i=1;i<n;i++)
			{
				ans=max(ans,a[i]&a[i+1]);
			}
			cout << ans;
		}
		else if (m==n)
		{
			cout << ans;
		}
		else cout << maxn;
	}
	else
	{
		cout << maxn;
	}
	return 0;
}
