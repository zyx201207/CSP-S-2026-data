#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n[10];
	string a, b, s1, s2;
	cin >> a >> s1 >> b >> s2;
	if(a != b || a == "01" || a == "16" || b == "01" || b == "16")
	{
		cout << "0000";
		return 0;
	}
	n[0] = 1;
	if(s1[0] == s2[0] && s1[1] == s2[1])
	{
		n[1] = 1;
	}
	else
	{
		cout << "1000";
		return 0;
	}
	if(s1[2] <= 'C' && s2[2] <= 'C')
	{
		n[2] = 1;
	}
	else if(s1[2] >= 'D' && s2[2] >= 'D')
	{
		n[2] = 1;
	}
	else
	{
		cout << "1100";
		return 0;
	}
	if(abs(s1[2] - s2[2]) == 1)
	{
		if(s1[2] == 'D' && s2[2] == 'C')
		{
			n[3] = 0;
		}
		else if(s1[2] == 'C' && s2[2] == 'D')
		{
			n[3] = 0;
		}
		else
		{
			n[3] = 1;
		}
	}
	else
	{
		cout << "1110";
		return 0;
	}
	for(int i = 0; i <= 3; i++)
	{
		cout << n[i];
	}
	return 0;
} 
