#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n;
long long t, a;
string c, s;
int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
		cin >> a >> c;
		for (int i = 1; i <= a; i++)
			s += c;
		t += a;
	}
	long long l, rp, cnt = 0;
	if (t % 2 == 0)
	{
		l = t/2-1;
		rp = l + 1;
	}
	else
	{
		l = t/2-1;
		rp = l + 1;
	}
	for (int i = 1; i <= t/2; i++)
	{
		if (s[l] != s[rp])
			cnt++;
		l--;
		rp++;
	}
	cout << cnt;
    return 0;
}
