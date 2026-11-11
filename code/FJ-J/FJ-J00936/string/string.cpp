#include <bits/stdc++.h>
using namespace std;
long long n,ans = 0,a[200005];
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	a[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j=1;j <= a[i];j++)
		{
			s[j] = c[j];
		}
	}
	bool f = true;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= a[i];j++)
		{
			if (s[j] != s[j - 1])
			{
				f = false;
			}
		}
	}
	if (f = true)
	{
		cout << "0";
	}
	return 0;
}
