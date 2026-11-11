#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long a[n+5];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		long long ma=0;
		for (int i = 0; i < n; i++)
	    {
	    	ma=max(a[i],ma);
	    }
	    cout << ma;
	}
	else if(m==n)
	{
		long long yu=a[0];
		for (int i = 1; i < n; i++)
	    {
		    yu=yu&a[i];
	    }
	    cout << yu;
	}
	else if(m==2)
	{
		sort(a,a+n);
		int x=a[n-1]&a[n-2];
		cout << x;
	}
	return 0;
}
