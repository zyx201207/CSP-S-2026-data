#include<bits/stdc++.h>
#define int long long
#define il inline
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],ans;
int s[N];

il bool chk(int x)
{
	for(int i=x;i<=n;i++)
	{
		int d = a[i] * (x-1);
		int lw = d - (s[i-1] - s[i-x]);
		if(lw - m <= 0)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	int l = 1,r = n;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(chk(mid) && l != mid)
		{
			l = mid;
			ans = mid;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}

/*
5 5
1 2 4 8 9
*/
