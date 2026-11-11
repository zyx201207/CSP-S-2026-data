#include <bits/stdc++.h>
using namespace std;


bool side(string s1, string s2)
{
	return (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')));
}

bool near(string s1, string s2)
{
	return (((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) || ((s1[2] == 'A' || s1[2] == 'B') && (s2[2] == 'A' || s2[2] == 'B')) || ((s1[2] == 'C' || s1[2] == 'B') && (s2[2] == 'C' || s2[2] == 'B')));
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && side(s1,s2)) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && side(s1,s2) && near(s1,s2)) cout << 1;
	else cout << 0;
	return 0;
}
