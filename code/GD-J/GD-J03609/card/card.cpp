#include<bits/stdc++.h>
using namespace std;
long long n,p,m,a[1000005],b[1000005],k,l[1000005],o[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	
	b[a[i]]=i;
	o[a[i]]++;
}
	for(int i=1;i<=m;i++)
	{
		long long x=b[i];
		while(x<=n)
		{
			l[a[x]]+=o[i];
			x=b[a[x]]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
	
		cout<<l[i]<<" ";
	
	}
	return 0;
}
