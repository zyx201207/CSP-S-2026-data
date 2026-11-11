#include <bits/stdc++.h>
using namespace std;
int x=0, y=0, z = 0, w = 0;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0;i < 2;i++)
	{
		x+=x*10+(c1[i]-'0');
		y+=y*10+(c2[i]-'0');
	}
	if(x!=y)
	{
		cout << 0 << " " << 0 << " " << 0 << " " << 0;
		return 0;
	}
	else
	{
		cout << 1 << " ";
	}
	for (int i = 0;i < 2;i++)
	{
		z+=z*10+(s1[i]-'0');
		w+=w*10+(s2[i]-'0');
	}
	if (z!=w)
	{
		cout << 0 << " " << 0 << " " << 0;
		return 0;
	}
	else
	{
		cout << 1 << " ";
	}
	if (('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||('D'<=s1[2]&&'F'>=s1[2]&&'D'<=s2[2]&&'F'>=s2[2]))
	{
		cout << 1 << " ";
	}
	else
	{
		cout << 0 << " " << 0;
		return 0;
	}
	if (s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
