#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int a[200005],ans;
void dfs(int h,int cnt,int sum)
{
	if (cnt == m)
	{
		ans = max(ans,sum);
		return;
	}
	if (h > n) return;
	dfs(h + 1,cnt,sum);
	if (cnt == 0) dfs(h + 1,cnt + 1,a[h]);
	else dfs(h + 1,cnt + 1,sum & a[h]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	int sum,maxn = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (i == 1) sum = a[i];
		else sum &= a[i];
		maxn = max(maxn,a[i]);
	}
	if (n <= 2000)
	{
		dfs(1,0,0);
		cout << ans;
	}
	else
	{
		int l = 0,kk = n;
		bool b = 1;
		while (kk > 1)
		{
			if (kk & 1 == 1)
			{
				b = 0;
				break;
			}
			kk /= 2;
			l++;
		}
		if (b)
		{
			int pp = (int)pow(2,l - 1);
			if (pp < m) cout << 0;
			else
			{
				int res = a[n];
				for (int i = n - 1;i > n - m;i--) res &= a[i];
				cout << res;
			}
		}
		else
		{
			sort(a + 1,a + n + 1,greater<int>());
			if (maxn < 4)
			{
				if (a[m] == 1) cout << 0;
				else cout << a[m];
			}
			else cout << a[m];
		}
	}
	
	return 0;
}
