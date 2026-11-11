#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n; 
string s, str;
ll cnt = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int j = 0;j < a;j++)
		{
			s += c;
		}
	}
	str = s;
	reverse(s.begin(), s.end());
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] != str[i])
			cnt++;
	}
	cout << cnt / 2;
	return 0;
} 
