#include <iostream>
#include <algorithm>
using namespace std;
int n, ans = 0;
long long m, a[500010];

int main()
{
	// 四组样例都过，预期得分100pts 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	ans = 1;
	long long used = 0;
	while (r != n)
	{
		// 新增数值的开销：原本线段长度 x 差值 
		long long dif = a[r + 1] - a[r];
		used += dif * (r - l + 1);
		r++;
		while (l < r && used > m)
		{
			used -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
 } 
