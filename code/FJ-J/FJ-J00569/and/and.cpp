#include <bits/stdc++.h>
using namespace std;

long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(a[i]<a[i+1])
			{
				swap(a[i],a[i+1]);
			}
		}
	}
	int x=a[1]&a[2];
	for(int i=3;i<=m;i++)
	{
		x&a[i];
	}
	cout<<x;
	return 0;
}
