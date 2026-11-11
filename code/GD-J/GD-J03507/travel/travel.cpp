#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int x1, y1;
	x1 = (s1[0] - '0') * 10 + s1[1] - '0';
	y1 = s1[2] - 'A' + 1;
	if(y1 == 4)
		y1++;
	int x2, y2;
	x2 = (s2[0] - '0') * 10 + s2[1] - '0';
	y2 = s2[2] - 'A' + 1;
	if(y2 == 4)
		y2++;
	bool f1 = (c1 == c2 ? true : false);
	bool f2 = (x1 == x2 ? true : false);
	bool f3 = ((y1 < 4 && y2 < 4) || (y1 > 4 && y2 > 4) ? true : false);
	bool f4 = (abs(y1 - y2) == 1 ? true : false);
	if(f1)
		cout << 1;
	else
		cout << 0;
	if(f1 && f2)
		cout << 1;
	else
		cout << 0;
	if(f1 && f2 && f3)
		cout << 1;
	else
		cout << 0;
	if(f1 && f2 && f3 && f4)
		cout << 1;
	else
		cout << 0;
	return 0;
}
