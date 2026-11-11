//GZ-J00065遵义第四中学李子煜
#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans = 0,k = 0;
	string s;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1;j <= a[i];j++)
		{
			s = s+c[i];
		}
		k += a[i];
	}
	if (k % 2 == 0)
	{
		for (int i = 1;i <= k/2;i++)
		{
			if (s[i] != s[k-i+1])
			{
				ans++;
			}
		}
	}
	else
	{
		for (int i = 1;i <= k/2+1;i++)
		{
			if (s[i] != s[k-i+1])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
