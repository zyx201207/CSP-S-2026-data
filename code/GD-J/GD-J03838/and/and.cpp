#include <bits/stdc++.h>
using namespace std;
int n,m,t,l;
int a[50000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int maxn = -1;
	for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
		if (a[i] > maxn)
		{
		    a[i] = maxn;
		}	
	}
	if (m == 1)
	{
		cout << maxn;
		return 0;
	}
	for (int i = 1;i < n;i++)
	{
    	for (int i = i+1;i < n;i++)
		{
			
		    if (a[i]&a[j+1] > maxn)
		    {
		        a[i]&a[j+1] = maxn;
		        t = a[i];
		        l = a[j]
		    }
		}	
	}
	cout << maxn;
	return 0;
}
