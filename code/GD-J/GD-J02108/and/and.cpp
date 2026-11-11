#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int n,m;
int a[200010];
const int MAXX = 0x7fffffffffffffff;
int ans = -1;
int cnt = 0;

void dfs(int step,int t)
{
	if (step > n) return;
	if (cnt == m)
	{
		ans = max(ans,t);
//		cout << t << ' ' << step << endl;
		return;
	}
	else
	{
		cnt++;
//		cout << (t & a[step+1]) << ' ';
		dfs(step+1,(t & a[step+1]));
		cnt--;
		dfs(step+1,t);
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	dfs(0,MAXX);
	cout << ans;
	return 0;
}
