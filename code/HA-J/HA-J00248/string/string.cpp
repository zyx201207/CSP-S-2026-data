#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long c;
	char d;
	for(int i = 1;i <= n;i++)
	{
		cin >> c >> d;
		for(int j = 1;j <= c;j++)
		{
			a += d;
		}
	}
	for(int r = 0;r <= floor(a.length()*1.0 / 2);r++)
	{
		if(a[r]!=a[a.length()-r-1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
