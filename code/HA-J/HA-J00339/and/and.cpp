#include <bits/stdc++.h>
using namespace std;
int n,m,sum,a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","e",stdout);
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]>maxn)
		{
			sum=a[i];
		}
	}
	cout<<sum;
	return 0;
}