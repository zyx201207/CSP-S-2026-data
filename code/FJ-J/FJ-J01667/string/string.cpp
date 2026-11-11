#include <bits/stdc++.h> 
using namespace std;
int n,a[1000000000000],ans;
char c[10000000000000];
bool flag = 1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	for (int i = 1;i <= (n+1) / 2;i++)
	{
		if ((c[i] != c[n-i+1]) || (a[i] != a[n-i+1]))
		{
			flag = 0;
		}
	}
	if (flag)
	{
		cout << "0";
	}
	else
	{
		for (int i = 1;i <= (n+1)/2;i++)
		{
			ans+=a[i];
		}
		cout << ans;
	}
	return 0;
}
