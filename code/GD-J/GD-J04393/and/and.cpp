#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long d=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=i;j>m;j--)
		{
			long long c=a[i];
			for(int k=0;k<m;k++)
			{
				c=c&a[j-k];
			}
		    d=max(c,d);
		}
	}
	cout<<d;
	return 0;
}

