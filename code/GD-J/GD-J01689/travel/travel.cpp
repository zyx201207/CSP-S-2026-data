#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c_1, s_1, c_2, s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	if(c_1 != c_2)
	{
		cout << "0000";
		return 0;
	}
	else cout << 1;
	int a_1 = 0, a_2 = 0;
	a_1 = (a_1 + (s_1[0] - '0')) * 10 + (s_1[1] - '0');
	a_2 = (a_2 + (s_2[0] - '0')) * 10 + (s_2[1] - '0');
	if(a_1 != a_2)
	{
		cout << "000";
		return 0;
	}
	else cout << 1;
	char x = s_1[2], y = s_2[2];
	if(x < y)
	{
		swap(x, y);
	}
	if(x - y > 2)
	{
		cout << "00";
		return 0;
	}
	if((x == 'D' && y == 'B') || (x == 'D' && y == 'C') || (x == 'E' && y == 'C'))
	{
		cout << "00";
		return 0;
	}
	else cout << 1;
	if(abs(x - y) == 1)
	{
		cout << 1;
	}
	else cout << "0";
	return 0;
}
