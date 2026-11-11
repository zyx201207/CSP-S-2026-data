#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	int r1 = (s1[0] - '0') * 10 + (s1[1] - '0'), r2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (r1 != r2)
	{
		cout << "1000";
		return 0;
	}
	char ch1 = s1[2], ch2 = s2[2];
	if (ch1 > ch2) swap(ch1, ch2);
	if (ch2 > 'C' && ch1 < 'D')
	{
		cout << "1100";
		return 0;
	}
	if (ch2 == 'C' && ch1 == 'A') cout << "1110";
	else cout << "1111";
	return 0;
}
