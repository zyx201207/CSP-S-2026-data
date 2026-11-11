#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int myabs(int x)
{
	if (x < 0) return -x;
	return x;
}

bool check(char a, char b)
{
	if (a == 'A' || a == 'B' || a == 'C')
	{
		if (b == 'A' || b == 'B' || b == 'C') return true;
		return false;
	}
	else
	{
		if (b == 'D' || b == 'E') return true;
		return false;
	}
	return false;
}

signed main()
{
	freopen("tarvel.in", "r", stdin);
	freopen("tarvel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) { cout << "0000" << endl; return 0; }
	
	string ans = "1";
	if (s1.substr(0, 2) == s2.substr(0, 2))
	{
		ans += '1';
		if (check(s1[2], s2[2]))
		{
			ans += '1';
			if (myabs(s1[2] - s2[2]) == 1) { cout << ans << '1' << endl; return 0; }
			else { cout << ans << '0' << endl; return 0; }
		}
		else { cout << ans << "00" << endl; return 0; }
	}
	else { cout << ans << "000" << endl; return 0; }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

