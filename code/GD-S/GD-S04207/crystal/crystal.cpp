#include<bits/stdc++.h>
using namespace std;
int n,s=1,l=1;
long long m,a[500005],k,p=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		k=a[i]-a[i-1];
		k=k*(i-l);
		p+=k;
		while(p>m&&l<i)
		{
			p=p-a[i]+a[l];
			l++;
		}
		s=max(s,i-l+1);
	}
	printf("%d",s);
	return 0;
}
