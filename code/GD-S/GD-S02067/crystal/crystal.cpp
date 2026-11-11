#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
int n, a[N], b[N];
int m;
int maxn, minn;
int ans;
bool check(int p, int x)
{
	int tot = a[x] * (x - p);
	int nw = b[x - 1] - b[p - 1];
	if(tot - nw <= m) return true;
	return false;
}
void make(int x)
{
	int num = 0;
	int l = 1, r = x - 1;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid, x))
		{
			num = x - mid + 1;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;	
		}
	}
	ans = max(ans, num);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++)
	{
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		make(i);
	}
	cout << ans << endl;
	return 0;
}

