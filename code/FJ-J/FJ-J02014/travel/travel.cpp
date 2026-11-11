#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b1 = c1 == c2,
		 b2 = b1 && s1[0] == s2[0] && s1[1] == s2[1], b3 = 0, b4 = 0;
	char t1 = s1[2], t2 = s2[2];
	if (t1 == 'D' && t2 == 'F' || t1 == 'F' && t2 == 'D')
	{
		b3 = b2 && 1;
		b4 = b3;
	}
	else
	{
		if (t1 != 'D' && t1 != 'F' && t2 != 'D' && t2 != 'F')
			b3 = b2 && 1;
		b4 = b3 && abs(t1 - t2) == 1;
	}
	printf("%d%d%d%d\n", b1, b2, b3, b4);
	return 0;
}
