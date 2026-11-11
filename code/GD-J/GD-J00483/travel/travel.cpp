#include <bits/stdc++.h>
using namespace std;

int x[15] = {0,1,2,2,3,4,5,2,1,3,2,5,4};
int y[15] = {0,2,1,3,2,5,4,1,2,2,3,4,5};

int f1(string s1,string s2)
{
	if (s1[2] <= 'C' && s2[2] <= 'C')
	{
		return 1;
	}
	if (s1[2] >= 'D' && s2[2] >= 'D') 
	{
		return 1;
	}
	return 0;
}

int f2(string s1,string s2)
{
	for(int i = 1;i <= 12;i++)
	{
		if ((s1[2] - 'A' + 1) == x[i] && (s2[2] - 'A' + 1) == y[i])
		{
			return 1;
		}
	}
	return 0;
}

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin >> a >> s1 >> b >> s2;
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << s1[1] << s1[2] << " " << s2[0] << s2[1] << s2[2] << endl;
	if (a == b)
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
	}
	if (a == b && s1[0] == s2[0] && s1[1] == s2[1])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (a == b && s1[0] == s2[0] && s1[1] == s2[1] && f1(s1,s2))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (a == b && s1[0] == s2[0] && s1[1] == s2[1] && f2(s1,s2))
	{
		cout << 1; 
	}
	else
	{
		cout << 0;
	}
	return 0;
} 
