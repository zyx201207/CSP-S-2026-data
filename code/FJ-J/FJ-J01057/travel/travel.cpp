#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	cin >> a >> s1 >> b >> s2;
	if(a != b)
	{
		cout << "0000";
		return 0;
	}
	if((s1[0] != s2[0])||(s1[1] != s2[1]))
	{
		cout << "1000";
		return 0;
	}
	if(s1[2] >= 'D')
	{
		if(s2[2] < 'D')
		{
			cout << "1100";
			return 0;
		}
	}
	if(s1[2] < 'D')
	{
		if(s2[2] >= 'D')
		{
			cout << "1100";
			return 0;
		}
	}
	if(abs(s2[2] - s1[2]) == 1)
	{
		cout << "1111";
		return 0;
	}
	cout << "1110";
	return 0;
}
//fc travel.out travel.ans
