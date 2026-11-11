#include <iostream>
using namespace std;
long long n, a[200005], cnt, sum, g;
char c[200005];
string s; 
long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> a[1] >> c[1];
	sum += a[1];
	g = a[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
		g = gcd(g, a[i]);
	}
	sum /= g;
	for (int i = 1; i <= n; i++)
	{
		s += string(a[i] / g, c[i]);
	}
	for (long long i = 0; i < sum / 2; i++)
	{
		if (s[i] != s[sum - i - 1])
		{
			cnt++;
		}
	}
	cout << cnt * g;
	return 0;
} 
