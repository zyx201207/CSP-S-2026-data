#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string c1, s1, c2, s2;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	string a = s1.substr(0, 2), b = s2.substr(0, 2);
	char c = s1[2], d = s2[2];
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b && ((c <= 'C' && c >= 'A' && d <= 'C' && d >= 'A') || (c <= 'F' && c >= 'D' && d <= 'F' && d >= 'D'))) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b && ((c == 'A' && d == 'B') || (c == 'B' && d == 'C') || (c == 'D' && d == 'F') || (c == 'B' && d == 'A') || (c == 'C' && d == 'B') || (c == 'F' && d == 'D'))) cout << 1;
	else cout << 0;
	return 0;
}

