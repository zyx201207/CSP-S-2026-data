#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	if(m==1)
	{
		cout << a[n-1];
	}
	else if(m==2)
	{
		long long ans=0;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				ans = max(ans, a[i]&a[j]);
			}
		}
		cout << ans;
	}
	else if(m==n)
	{
		long long ans=a[0];
		for(int i=1; i<n; i++)
		{
			ans = ans&a[i];
		}
		cout << ans;
	}
	return 0;
 } 
