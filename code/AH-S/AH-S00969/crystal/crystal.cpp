#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	a[0]=a[1];
    sort(a+1,a+n+1);
    int mx=0,l=1,r=1;
    long long sum=0;
    while(l<=r&&r<=n)
    {
    	if(sum<=m)
    	{
		    r++;
    	    sum+=(a[r]-a[r-1])*(r-l);
		}
		if(sum<=m) mx=max(mx,r-l+1);
    	while(sum>m) 
		{
			sum-=a[r]-a[l];
			l++;
		}
		if(sum<=m) mx=max(mx,r-l+1);
	}
	printf("%d",mx);
	return 0;
}
