#include<bits/stdc++.h>
using namespace std;
int n,a[200020];
long long sum,s[200020],l,r;
char c[200020];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		s[i]=s[i-1]+a[i];
	}
	l=1,r=s[n];
	while(l<r)
	{
		int sl=lower_bound(s+1,s+n+1,l)-s;
		int sr=lower_bound(s+1,s+n+1,r)-s;
		int mn=min(a[sl],a[sr]);
		if(c[sl]!=c[sr]) sum+=mn;
		a[sl]-=mn;
		a[sr]-=mn;
		l+=mn;
		r-=mn;
	}
	printf("%lld",sum);
	return 0;
}
