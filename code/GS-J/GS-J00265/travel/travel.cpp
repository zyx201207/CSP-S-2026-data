#include<bits/stdc++.h>

using namespace std;
int a,b;
string s,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >> c;
	int a1 = (s[0] - '0') * 10 + (s[1] - '0');
	int b1 = (c[0] - '0') * 10 + (c[1] - '0');
	bool f = (a == b);
	bool f1 = f && (a1 == b1);
	bool f2 = f1 && (s[2] >= 'D' && c[2] >= 'D' || s[2] < 'D' && c[2] < 'D');
	bool f3 = f2 && (s[2] >= 'D' || max(s[2],c[2]) - min(s[2],c[2]) == 1);
	cout << f << f1 << f2 << f3;
	return 0;
}
