#include <bits/stdc++.h>
using namespace std;
int n,l=0,a[200005];
long long ans=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]!=c[n-i+1])
		{
			ans=max(a[i],a[n-i+1]);
			for (int j=ans;j>=1;j--)
			{
				if (c[j]==c[i])
				{
					ans=ans-a[j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
