#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	string s[200005];
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> s[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ans += a[i];
	}
	ans /= 2;
	cout << ans;
	return 0;
}
