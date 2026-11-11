#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	int x=(b[0]-'0')+(b[1]-'0');
	int y=(d[0]-'0')+(d[1]-'0');
	if (a==c)
		cout << 1;
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (x==y)
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	if ((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
	{
		cout << 1;
	}
	else
	{
		cout << 0 << 0;
		return 0;
	}
	if (b[2]-1==d[2]||b[2]+1==d[2])
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}

