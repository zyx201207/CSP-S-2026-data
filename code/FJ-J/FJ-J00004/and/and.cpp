#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		long long maxv=0;
		for(int i=1;i<n;i++)
		{
			maxv=max(maxv,a[i]);
		}
		cout << maxv;
	}
	else
	{
		int maxv;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					int s=int(a[i]&a[j]);
					maxv=max(maxv,s);
				}
			} 
		}
		cout << maxv;
	}
	return 0;
}
