#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int a;
		char b;
		cin >> a >> b;
		for (int j = 1;j <= a;j++)
		{
			s += b;
		}
	}
	for (int i = 1;i <= s.length();i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			s[s.length() - 1 - i] = s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
