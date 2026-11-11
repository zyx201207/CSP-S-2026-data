#include<bits/stdc++.h>
using namespace std;
typedef long long inf;
inf n,a[200005],ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		//printf("%d  %d\n",i,n);
	}
	
	inf p1=1,p2=n;
	while(p1<=p2)
	{
		if(a[p1]>a[p2])
		{
			a[p1]-=a[p2];
			if(c[p1]!=c[p2])ans+=a[p2];
			p2--;
		}
		if(a[p1]==a[p2])
		{
			if(c[p1]!=c[p2])ans+=a[p2];
			p1++;p2--;
		}
		if(a[p1]<a[p2])
		{
			a[p2]-=a[p1];
			if(c[p1]!=c[p2])ans+=a[p1];
			p1++;
		}
	}
	printf("%lld",ans);
	return 0;
}
