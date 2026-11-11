#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,t1,t2;
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	cin >> a[1] >> c[1];
	for(int i = 2;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		if(c[i] != c[i-1])
		{
			t1 = 1;
		}
		if(i > n/2+(n%2))
		{
			if(a[i] != a[n-i+1])
			{
				t2 = 1;
			}
		}
	}
	if(t1 == 0)
	{
		cout << "0";
		return 0;
	}
	if(t2 == 0)
	{
		for(int i = 1;i <= n/2;i++)
		{
			if(c[i] != c[n-i+1])
			{
				ans += a[i];
			}
		}
		cout << ans;
		return 0;
	}
	cout << "0";
} 
