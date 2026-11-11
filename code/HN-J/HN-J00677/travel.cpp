#include <bits/stdc++.h>;
using namespace;

char c1,s1,c2,s2;
char a;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == "01" || c2 == "01") a = a + "0";
	if (c1 == "16" || c2 == "16") a = a + "0";
	if (c1 == c2) a = a + "1";
	else {
		a = a + "0";
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) a = a + "1";
	else a = a + "0";
	if ((s1[2] == "D" || s1[2] == "E") && (s2[2] == "D" || s2[2] == "E")) a = a + "1";
	if ((s1[2] == "A" || s1[2] == "B" || s1[2] == "C") && (s2[2] == "A" || s2[2] == "B" || s2[2] == "C")) a = a + "1";
	else a = a + "0";
	cout << a;
	
}
