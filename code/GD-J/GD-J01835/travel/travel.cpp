#include <bits/stdc++.h>
using namespace std;

string s, s1, s2, s3;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> s1 >> s2 >> s3;
	if(s == s2)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s3[0] && s1[1] == s3[1])
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(((s1[2] - 'A') >= 3 && (s3[2] - 'A') >= 3) || ((s1[2] - 'A') < 3 && (s3[2] - 'A') < 3))
	{
		cout << 1;
	} 
	else
	{
		cout << "00";
		return 0;
	}
	if(abs((s1[2] - 'A') - (s3[2] - 'A')) == 1)
	{
		cout << "1";
	}
	else
	{
		cout << 0;
	}
}
