// travel
#include <iostream>
#define int long long
using namespace std;

string c1, s1, c2, s2;

int lev(char ch)
{
	if (ch == 'D' || ch == 'F') return 2;
	return 1;
}

char minc(char a, char b)
{
	return (a < b ? a : b);
}
char maxc(char a, char b)
{
	return (a > b ? a : b);
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else
	{
		if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
		else
		{
			if (lev(s1[2]) != lev(s2[2])) cout << "1100";
			else
			{
				char nc = minc(s1[2], s2[2]), xc = maxc(s1[2], s2[2]);
				if ((nc + 1) != xc) cout << "1110";
				else cout << "1111";
			}
		}
	}
	return 0;
}
