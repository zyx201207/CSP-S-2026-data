#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	map<char,int> mp;
	mp['A'] = 0;
	mp['B'] = 0;
	mp['C'] = 0;
	mp['D'] = 1;
	mp['F'] = 1;
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	bool f1,f2,f3,f4;
	f1 = (a == c);
	f2 = (b[0] == d[0] && b[1] == d[1]);
	f3 = (mp[b[2]] == mp[d[2]]);
	f4 = (abs(b[2]-d[2])==1);
	cout << f1;
	cout << (f1&&f2);
	cout << (f1&&f2&&f3);
	cout << (f1&&f2&&f3&&f4);
	return 0;
}

