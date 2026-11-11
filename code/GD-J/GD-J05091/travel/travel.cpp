#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
string s1,s2;
char x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s1 >> m >> s2;
	if(n == m)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	a = (s1[0] - '0') * 10 + s1[1] - '0';
	b = (s2[0] - '0') * 10 + s2[1] - '0';
	if(n == m && a == b)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	x = s1[2];
	y = s2[2];
	if(n == m && a == b && ((x <= 'C' && y <= 'C') || (x > 'C' && y > 'C')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(n == m && a == b && (x <= 'C' && y <= 'C') && abs((int)x - (int)y) == 1)
	{
		cout << 1;
	}
	else if(n == m && a == b && (x > 'C' && y > 'C') && abs((int)x - (int)y) == 2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
} 
