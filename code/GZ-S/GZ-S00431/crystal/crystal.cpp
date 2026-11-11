//张文涵 绥阳中学 Gz-S00431 
#include<bits/stdc++.h>

using namespace std;
const int maxn=5*1e5+1;
long long a[maxn];
int n,best=0;
long long m;
int cl(int c)
{
	int cnt=1;
	long long ans=0;
	for(int i=c-1;i>=1;i--)
	{
	    ans=ans+a[c]-a[i];
		if(ans<=m)
		{
			cnt++;
		}
		else continue;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		int w=cl(i);
		if(best<w)
		{
			best=w;
		}
	}
	printf("%d",best);
	return 0;
 } 
