#include <iostream>
using namespace std;

int q[200005];
char a[200005];

int main()
{
	freopen("string1.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, sum = 0;
	string s = "";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i] >> a[i];
		s += a[i] * q[i];
	}
	for (int i = s.size() - 1; i >= (s.size() - 1 + 2) / 2; i--)
	{
		if (s[i] != s[s.size() - i + 1])
		{
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}
