#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	
	if(s1[1] == s2[1] && s1[0] == s2[0])
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	
	if(s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D')
	{
		cout << 1;
		//cout << s1[2] << s2[2];
	}
	else
	{
		//cout << s1[2] << s2[2];
		cout << "00";
		return 0;
	}
	
	if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
