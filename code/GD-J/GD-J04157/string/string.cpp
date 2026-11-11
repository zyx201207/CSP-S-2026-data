#include<iostream>
#define int long long
using namespace std;
int n,a[200012],ans,l,r,sum1,sum2;
char c[200012];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1,r=n;
	sum1=a[1];
	sum2=a[n];
	while(l<r)
	{
		if(sum1>sum2)
		{
			if(c[l]!=c[r])ans+=sum2;
			sum1-=sum2;
			sum2=a[--r];
		}
		else
		{
			if(c[l]!=c[r])ans+=sum1;
			sum2-=sum1;
			sum1=a[++l];
		}
	}
	cout<<ans;
}
