#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
int a, b, c, d;
bool l = 0;
int vis[8];
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0;i < 2;i ++)
	{
		if(c1[i] != c2[i])
		{
			cout << a << b << c << d << '\n';
			return 0;
		}
		
	}
	a = 1;
	for(int i = 0;i < 2;i ++)
	{
		if(s1[i] != s2[i])
		{
			cout << a << b << c << d << '\n';
			return 0;
		}
	}
	b = 1;
	if(!((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')))
	{
		cout << a << b << c << d << '\n';
		return 0;
	}
	c = 1;
	int k1 = s1[2] - 'A';
	int k2 = s2[2] - 'A';
//	cout << s1[1];
	vis[k1] = 1;
	vis[k2] = 1;
//	cout << k1 <<' ' << k2;
	for(int i = 1;i < 6;i ++)
	{
		if(vis[i] == 1 && vis[i - 1] == 1)
		{
			d = 1;
			cout << a << b << c << d << '\n';
			return 0;
		}
	}
	cout << a << b << c << d << '\n';
	return 0;
}
