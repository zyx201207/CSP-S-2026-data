#include <iostream> 
#include <algorithm>
#define ll long long
using namespace std;
const int N = 500005;
ll n, m, a[N], l = 0, r = N, b[N], ans = 1, x, head = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	x = a[1];
	m -= a[1];
	for(int i = 2 ; i <= n ; i++)
	{
		if(a[i] == x)
		{
			ans = max(ans, i - head + 1);
			continue;
		}
		ll siz = i - head + 1;
		while(m < (a[i] - x) * siz)
		{
			m += (x - a[head]);
			siz--;
			head++;
		}
		m -= (a[i] - x) * siz;
		x = a[i];
		siz++;
		ans = max(ans, siz);
	}
	cout << ans << "\n";
	return 0;
}
