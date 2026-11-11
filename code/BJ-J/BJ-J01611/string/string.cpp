#include <iostream>
#include <iomanip>

using namespace std;

using u64 = unsigned long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	static int a[200001];
	static char b[200001];
	u64 len = 0;
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		len += a[i];
	}
	
	u64 res = 0;
	for (int i = 1, j = n; i < j;)
	{
		const int mn = min(a[i], a[j]);
		a[i] -= mn;
		a[j] -= mn;
		
		if (b[i] != b[j]) res += mn;
		
		if (!a[i]) ++i;
		if (!a[j]) --j;
	}
	
	cout << res << '\n';
	
	return 0;
}
