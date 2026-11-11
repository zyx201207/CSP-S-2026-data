#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100000 + 5;
long long n, m, ans;
long long a[N], f[N];
bool b = true;
bool check(int ans)
{
	long long sum = 0, a = 0;
	for (int i = ans - 1; i >= 1; i --)
	{
		a += f[i];
		sum = sum + a;
	//cout << "sum: " << sum << endl;
	}
	if (sum <= m) return true;
	return false;
}
int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crysral.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i ++)
	{
		f[i] = a[i + 1] - a[i];
		if(i != 1 && f[i] != f[i - 1]) b = false;
	}
	if(b == true){
		cout << m / f[1] << endl;
		return 0;
	}
	
	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		//cout << l << " " << r << " " << mid << endl;
		if (check(mid)) l = mid + 1;
		else r = mid;
	} 
	cout << mid << endl;
	return 0;
}
// 5 5 1 2 5 8 9
// 5 8 -3 -1 2 2 7
