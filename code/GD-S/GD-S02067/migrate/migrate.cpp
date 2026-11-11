#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;
int c, t, n, d;
int a[N];
int cnt, sum;
void dfs(int p, int tar, int step)
{
//	cout << p << " " << tar << " " << step << endl;
	if(p == tar)
	{
		if(step < sum)
		{
			cnt = 1;
			sum = step;
		}
		else if(step == sum)
		{
			cnt ++;
		}
		return ;
	}
	for(int i = p + 1;i <= n;i ++)
	{
		int dis = a[i] - a[p];
		if(dis > d) break;
		dfs(i, tar, step + 1);
	}
}
bool check(int u, int v)
{
	cnt = 0, sum = INF;
	dfs(u, v, 0);
	if(cnt == 2) return true;
	return false;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		int ans = 0;
		for(int i = 1;i <= n;i ++) cin >> a[i];
		for(int i = 1;i < n - 2;i ++)
		{
			for(int j = i + 3;j <= n;j ++)
			{
				if(check(i, j)) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

