#include <bits/stdc++.h>
using namespace std;
int n,a,ans,t;
string c,s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (int j = t+1;j <= t+a;j++)
		{
			s[j] = c;
		}
		t += a;
	}
	for (int i = 1;i <= t/2;i++)
	{
		if(s[i] != s[t+1-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
