#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,x,a[200005],maxn=-1;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[j]&a[i])>=maxn)
			{
				maxn=a[i]&a[j];
			}
		}
	}
	cout<<maxn;
	return 0;
}
