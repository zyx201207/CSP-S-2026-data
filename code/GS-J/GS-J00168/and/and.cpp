#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxn = 0;
    cin >> n >> m;
    long long a[n+5],l,r;
    for (int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	
	for(int i = 1;i <= n;i++)
	{
		int pp = a[i];
		l = i;
		for (int j = 1;j < m;j++)
		{
			if (i+j>n)
			{
				pp = pp & a[l+j-n];
			}
			else
			{
				pp = pp & a[l+j];
			}
			
		}
		if (pp > maxn)
		{
			maxn = pp;
		}
	}
	cout << maxn;
    return 0;
}
