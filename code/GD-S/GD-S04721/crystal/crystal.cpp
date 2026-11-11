#include<bits/stdc++.h>
using namespace std;
int n,maxa;
long long m,a[500005];
unsigned long long k;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int l=1,r=2;r<=n;r++)
	{
		k+=(a[r]-a[r-1])*(r-l);
		while(k>m)
		{
			k-=a[r]-a[l++];
		}
		maxa=max(maxa,r-l+1);
	}
	printf("%d",maxa);
	return 0;
}

