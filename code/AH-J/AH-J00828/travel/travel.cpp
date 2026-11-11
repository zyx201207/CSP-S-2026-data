#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int f[4];
int main()
{
	freopen("travel", "r", stdin);
	freopen("travel", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = max(s1[3], s2[3]);
	int b = min(s1[3], s2[3]);
	if(c1 == c2) f[1] = 1;
	else 
	{
		cout << "0000";
		return 0;
	}
	if (s1[2] == s2[2] || s1[1] == s2[1]) f[2] = 1;
	else 
	{
		cout << "1000";
		return 0;
	}
	if (a - b <= '2') f[3] = 1;
	else
	{
		cout << "1100";
		return 0;
	}
	if (a - b < '1') f[4] = 1;
	else 
	{
		cout << "1110";
		return 0;
	}
	for (int i = 1; i <= 4; i++) cout << f[i];
	return 0;
}
