#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int n;
long long m;

bool check(int x)
{
	if(x == 1) return true;
	long long minn = LONG_LONG_MAX;
	for(int i=x;i<=n;i++)
	{
		int l = i - x + 1,r = i - 1;
		long long js = 1LL * a[i] * (x - 1);
		long long md = sum[r] - sum[l-1];
		long long cr = js - md;
		minn = min(minn,cr);
	}
	return minn <= m;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i] = sum[i-1] + a[i];
	}
	int l = 1,r = n;
	int ans = -1;
	while(l <= r)
	{
		int mid = (l + r + 1) / 2;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
