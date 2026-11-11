#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
string w1 = "", w2 = "";
string ans;

int get(char c)
{
	if(c == 'A') return 0;
	if(c == 'B') return 1;
	if(c == 'C') return 2;
	if(c == 'D') return 114514;
	return 114515;
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	w1 = w1 + s1[0] + s1[1];
	w2 = w2 + s2[0] + s2[1];
	if(c1 == c2) ans += '1';
	else ans += '0';
	if(c1 == c2 && w1 == w2) ans += '1';
	else ans += '0';
	if(c1 == c2 && w1 == w2 && ((s1[2] <= 'C') ^ (s2[2] <= 'C')) == 0) ans += '1';
	else ans += '0';
	if(c1 == c2 && w1 == w2 && abs(get(s1[2]) - get(s2[2])) == 1) ans += '1';
	else ans += '0';
	cout << ans << endl;
	return 0;
}
