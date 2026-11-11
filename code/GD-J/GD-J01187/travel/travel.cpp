#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << 1;
	else
	{
		cout << "0000";
		return 0;
	}
	
	string s, k;
	s += s1[0]; s += s1[1];
	k += s2[0]; k += s2[1];
	if(s == k) cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	
	char c = s1[2], d = s2[2];
	if(abs(c - d) <= 2)
	{
		if(c == 'C' and d == 'D' or c == 'D' and d == 'C')
		{
			cout << "00";
			return 0;
		}
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	
	if(abs(c - d) == 1) cout << 1;
	else cout << 0;
	
	return 0;
}
