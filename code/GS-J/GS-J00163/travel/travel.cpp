#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		f = f + '1';
	}
	else
	{
		f = f + '0';
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		f = f + '1';
	}
	else 
	{
		f = f + '0';
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D')
	{
		f = f + '1';
	}
	else 
	{
		f = f + '0';
	}
	if(s1[0] == s2[0] && s1[1] + 1 == s2[1])   
	{
		f = f + '1';
	}

	else 
	{
		f = f + '0';
	}
	cout << f;
	return 0;
}
