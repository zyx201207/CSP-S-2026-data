#include <bits/stdc++.h>
using namespace std;

bool f1(char a, char b)
{
	if (a > b) swap(a, b);
	if (a == 'A' && b == 'B') return 1;
	if (a == 'A' && b == 'C') return 1;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'D' && b == 'F') return 1;
	return 0;
}

bool f2(char a, char b)
{
	if (a > b) swap(a, b);
	if (a == 'A' && b == 'B') return 1;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'D' && b == 'F') return 1;
	return 0;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) cout << 1;
	else cout << 0;
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f1(s1[2], s2[2])) cout << 1;
	else cout << 0;
	
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && f1(s1[2], s2[2]) && f2(s1[2], s2[2])) cout << 1;
	else cout << 0;
	
	return 0;
}
