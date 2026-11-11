#include<bits/stdc++.h>
using namespace std;
int const N=1e6;
long long s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=1,r=1,h1=0,h2=0,sum=0,maxn=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	while(sum<=m&&r<=n)
	{
		r++;
		h2++;
		sum=sum+(s[r]-s[r-1])*h2;
		maxn=max(maxn,r-l+1);
	}
	maxn--;
	sum=sum-(s[r]-s[r-1])*h2;
	r--;
	h2--;
	while(r<=n)
	{
		if(l!=r)
		{
			if(sum+(s[r+1]-s[r])*(h2-h1+2)<=m)
			{
				r++;
				h2++;
				sum=sum+(s[r]-s[r-1])*(h2-h1+1);
			}
			else
			{
				l++;
				h1++;
				sum=sum-(s[l]-s[l-1]);
			}
		}
		else
		{
			if(s[r+1]-s[r]<=m)
			{
				r++;
				h2++;
				sum=s[r]-s[r-1];
			}
			else
			{
				l++;
				r++;
				h1++;
				h2++;
				sum=0;
			}
		}
		maxn=max(maxn,r-l+1);
	}
	printf("%lld",maxn);
	return 0;
}
