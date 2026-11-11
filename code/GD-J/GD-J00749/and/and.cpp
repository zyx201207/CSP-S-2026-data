#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long

const int N = 2e5 + 10,M = 1e2 + 10;
int n,m,a[N],p[M];
bool vis[N];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		for(int j = 29;j >= 0;j --)
		{
			int res = (a[i] >> j) & 1;
			if (res) p[j] ++; 
		}
	}
	int ans = 0;
	for(int i = 29;i >= 0;i --)
	{
		if (p[i] < m) continue;
		for(int j = 1;j <= n;j ++)
		{
			if (vis[j] || ((a[j] >> i) & 1)) continue;
			vis[j] = 1;
			for(int k = 29;k >= 0;k --)
				if ((a[j] >> k) & 1) p[k] --;
		}
		ans += (1 << i);
	}
	cout << ans << endl;
	return 0;
}








