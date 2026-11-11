#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, l = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
		{
			s += c;
		}
	}
	for(int i = 0; i < s.size() / 2; i++)
	{
		if(s[i] == s[s.size() - 1 - i])
		{
			continue;
		}
		else
		{
			l++;
		}
	}
	cout << l;
	return 0;
} 
