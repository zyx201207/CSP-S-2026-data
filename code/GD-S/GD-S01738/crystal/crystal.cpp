#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[500005],ans;
void d(long long x,int cnt,long long c)
{
	cnt = cnt + (x - 1) * t[c];
	//cout << cnt << ' ' << x << endl;
	if (cnt <= m)
	{
		ans = max(ans,x);
	}
	else
	{
		return;
	}
	for (int i = c + 1;i <= n;i++)
	{
		d(x + 1,cnt,i);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		t[i] = a[i] - a[i - 1];
	}
	t[1] = 0;
	for (long long i = 1;i <= n;i++)
	{
		d(1,0,i);
	}
	cout << ans;
	return 0;
}
