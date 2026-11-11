#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l,ans=0;
	char c;
	string s;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> l >> c;
		s+=l*c;
	}
	for (int i=0;i<(sizeof(s)+1)/2;i++)
	{
		if (s[i]!=s[n-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
 } 
