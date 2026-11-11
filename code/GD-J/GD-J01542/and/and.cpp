#include <bits/stdc++.h>
#define int long long
using namespace std; 

int get1(int m)
{
	int cnt = 0;
	while (m)
	{
		if (m % 2) cnt++;
		m /= 2;
	}
	return cnt;
}
int a[200005];

bool cmp(int x,int y)
{
	if (get1(x) != get1(y)) return get1(x) > get1(y);
	return x > y;
}
signed main()
{
	// ÓÃscanf,printf!
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	int ans = a[1];
	for (int i = 2;i <= m;i++)
	{
		ans = ans ^ a[i];
	}
	cout << ans;
	return 0;
}
