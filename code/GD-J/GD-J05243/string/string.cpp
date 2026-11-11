#include <bits/stdc++.h>
using namespace std;

long long n, cnt, a[200005];
string s, s1, s2;

int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		char c;
		cin >> c;
		for (int j = 1; j <= a[i]; j++)
			s += c;
	}
	for (int i = 0; i <= s.size () / 2 - 1; i++)
		s1 += s[i];
	for (int i = s.size () - 1; i >= s.size () / 2 + 1; i--)
		s2 += s[i]; 
	for (int i = 0; i <= s1.size (); i++)
		if (s1[i] != s2[i])
			cnt++;
	cout << cnt;
	return 0;
}
