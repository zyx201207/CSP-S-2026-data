#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long m,n,a[500005],maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(long long i=1;i<=n-maxn;i++)
	{
		long long p=m,j=i;
		while(p>=(j*(a[j+1]-a[j])))
		{
			p-=(j*(a[j+1]-a[j]));
			j++;
		}
		maxn=max(maxn,j);
	}
	cout<<maxn;
	return 0;
}
