#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
char c[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	long long l=1,r=n,ans=0;
	while (l<r)
	{
		long long minn=min(a[l],a[r]);
		if (c[l]!=c[r])
		{
			ans+=minn;
		}
		a[l]-=minn;
		a[r]-=minn;
		if (a[l]==0)
		{
			l++;
		}
		else if (a[r]==0)
		{
			r--;
		}
	}
	cout << ans;
	return 0;
}
