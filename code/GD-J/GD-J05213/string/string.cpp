#include <bits/stdc++.h>
using namespace std;
string s;
long long ans,n;
long long p[200005];
char q[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> p[i] >> q[i];
		for(int j = 1;j <= p[i];j++)
		{
			s += q[i];
		}
	}
	long long l = s.length();
	for(int i = 0;i < l / 2;i++)
	{
		if(s[i] != s[l - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
	 
}
