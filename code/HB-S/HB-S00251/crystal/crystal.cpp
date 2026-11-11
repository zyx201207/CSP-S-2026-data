#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],c[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		c[i]=(a[i]-a[i-1]);
	}
	c[1]=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(0<=m-abs(c[i])*(i-1))
		{
			cnt++;
			m=m-abs(c[i])*(i-1);
		}
		else
		{
		    cnt++;
			printf("%lld",cnt-1);
			break;
		}
	}
	return 0;
}
