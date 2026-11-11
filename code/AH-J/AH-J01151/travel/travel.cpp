#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
char a, b, c, d;
int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> a >> b >> s1 >> c2 >> c >> d >> s2;
	if (c1 == c2)
		printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	if (a == c && b == d)
		printf("1");
	else
	{
		printf("000");
		return 0;
	}
	if (s1 <= "C" && (s2 == "A" || s2 == "B" || s2 == "C") || s1 > "C" && (s2 == "D" || s2 == "F"))
		printf("1");
	else
	{
		printf("00");
		return 0;
	}
	if (!((s1 == "A" && s2 == "C") || (s1 == "C" && s2 == "A")))
		printf("1");
	else
		printf("0");
	return 0;
}
