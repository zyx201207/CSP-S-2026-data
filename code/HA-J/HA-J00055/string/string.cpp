#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a1;
		string c1;
		cin >> a1 >> c1;
		for (int j = 1; j <= a1; j++)
		{
			s += c1;
		}
	}	
	string s1 = s;	
	reverse(s.begin(), s.end());
	if (s == s1)	{cout << 0; return 0;}
	//以下数值-0;
	int cnt = 0; 
	for (int i = 0; i <= (s1.size()-1)/2; i++)
	{
		if (s[i] != s1[i])	cnt++;
	}
	cout << cnt;
	return 0;
}
