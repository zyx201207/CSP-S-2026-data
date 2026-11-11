#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	if(!(s1[0] == s2[0] && s1[1] == s2[1]))
	{
		cout << "1000";
		return 0;
	}
	char a = s1[2], b = s2[2];
	if(!((a < 'D' && b < 'D') || (a > 'C' && b > 'C')))
	{
		cout << "1100";
		return 0;
	}
	if((a < 'D' && b < 'D'))
	{
		if(abs(int(a - b)) == 1) cout << "1111";
		else cout << "1110";
	}
	else cout << "1111";
	return 0;
}
