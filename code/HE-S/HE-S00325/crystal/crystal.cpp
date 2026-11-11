#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int a[510101];

bool check(int mid)
{
	int sum=0;
	for (int i = 1; i <= n; i++)
	{
		if (mid>=a[i]) sum+=mid-a[i];
	}
	return sum<=m;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	int l=1e13, r=-1e13;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l=min(l, a[i]);
		r=max(r, a[i]);
	}
	sort(a+1, a+1+n, greater<int>());
	//cout << l << " " << r << endl;
	int best=0x3f3f3f3f;
	while (l<=r)
	{
		int mid=(l+r)/2;
//		cout << mid << endl;
		if (check(mid))
		{
			l=mid+1;
			best=mid;	
		}	
		else r=mid-1;
	}
//	cout << best << endl;
	int ans=0, sum=0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i]<=best&&sum<=m)
		{
			ans++;
			sum+=best-a[i];
		} 
	}
	cout << ans;
	return 0;
}
//qwq

