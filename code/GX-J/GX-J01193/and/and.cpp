#include <bits/stdc++.h>
using namespace std;

int ba(int n)
{
	int x = 1;
	if(x < n && n < 2)
	{
		return 0;
	}
	for(int i = 1;i<=30;i++)
	{
		x *= 2;
		if(x < n && n < x*2)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int yix = 0;
	int ans = 0;
	bool begin = 1;
	unsigned long long int a[200005];
	long long int t[35];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	if(m == 1)
	{
		cout << a[n-1];
		return 0;
	}
	else
	{
		for(int i = 0;i<n;i++)
		{
			t[ba(a[i])]++;
		}
		for(int i = n-1;i >= 0;i--)
		{
			if(t[ba(a[i])]<m)
			{
				continue;
			}
			if(ans == 0 && begin)
			{
				ans = a[i];
				yix ++;
				begin = 0;
			}
			else
			{	
				ans &= a[i];
				yix ++;
			}
			if(yix == m)
			{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
