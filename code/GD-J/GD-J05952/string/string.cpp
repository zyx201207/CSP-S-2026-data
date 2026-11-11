#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long l = 0,ans = 0;
	cin >> n;
	int a[n];
	string c[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
	}
	for(int i=0;i<(l-1)/2+1;i++)
	{
		int d=i;
		long long d2 = l-i-1;
		string c1,c2;
		for(int o=0;o<n;o++)
		{
			if(d+1-a[o] > 0) d -= a[o];
			else
			{
				c1 = c[o];
				break;
			}
		}
		for(int o=0;o<n;o++)
		{
			if(d2+1-a[o] > 0) d2 -= a[o];
			else
			{
				c2 = c[o];
				break;
			}
		}
		if(c1 != c2) ans += 1;
	}
	cout << ans;
	return 0;
} 
