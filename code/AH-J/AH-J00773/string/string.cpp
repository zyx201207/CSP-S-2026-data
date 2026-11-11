#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, len, cnt;
string s1;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
		{
			s1 += c;
			len++;
		}
	}
	for(int i = 0; i < len / 2; i++)
	{
		//s2[i] = s1[len - 1 - i];
		if(s1[i] != s1[len - 1 - i]) cnt++;
	}
	cout << cnt;
	return 0;
}
