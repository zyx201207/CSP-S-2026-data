#include<bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	char m;
	string s = " ";
	for(int i = 1;i <= n;i++)
	{
		cin >> x >> m;
	}
	int len = s.length(),ans = 0;
	for(int i = 1;i <= s.length();i++)
	{
		if(s[i] != s[n - 1 + i])
			ans++;
	}
	if(ans % 2 == 0)
		cout << ans / 2;
	else cout << ans / 2 - 1;
	return 0;
}
