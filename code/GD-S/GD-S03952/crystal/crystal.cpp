#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],l=1,r=1,s=1,t;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	while(r<=n)
	{
		r++;
		t=t+(r-l)*(a[r]-a[r-1]);
		while(t>m)
		{
			t=t-(a[r]-a[l]);
			l++;
		}
		s=max(s,r-l+1);
	}
	printf("%lld",s);
}


