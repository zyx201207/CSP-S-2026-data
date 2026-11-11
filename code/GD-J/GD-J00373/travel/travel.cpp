#include <bits/stdc++.h>
#define int long long
#define F(i, s, t) for (int (i) = (s); (i) <= (t); ++(i))
#define outs(s) cout << (s) << ' '
#define outn(s) cout << (s) << '\n'
#define FILENAME "travel"
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1 = s1[2]-'A';
	int a2 = s2[2]-'A';
	cout << (c1 == c2);
	cout << ((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1]));
	cout << (((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1])) && ((a1 < 3) == (a2 < 3)));
	cout << ((((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1])) && ((a1 < 3) == (a2 < 3))) && (abs(a1 - a2) == 1));
	
	
	return 0;
} 
