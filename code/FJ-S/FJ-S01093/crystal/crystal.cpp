#include<bits/stdc++.h>
using namespace std;
//ÃÜÂë Oct31==Dec25? ¼À
//ÍòÊ¥½Ú==Ê¥µ®½Ú£¿ 

const int N = 500005;

int n, ans = 0;
long long a[N], b[N], s[N];
long long nw, m;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)b[i] = a[1] - a[i];
	for(int i = n; i >= 1; i--)s[i] = s[i + 1] + b[i];
	for(int i = 1; i <= n; i++)
	{
		int l = i, r = n, mid;
		while(l != r)
		{
			mid = (l + r + 1) >> 1;
			nw = s[i + 1] - s[mid + 1] - (mid - i + 1) * b[i];
			
			if(nw <= m)l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l - i + 1);
	}
	cout << ans;
	
	return 0;
}
