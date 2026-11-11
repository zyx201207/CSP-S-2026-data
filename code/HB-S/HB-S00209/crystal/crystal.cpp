#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],maxn=-1,minn=2147483647,c;
int main()
{
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    c=m;
    for(int i=1;i<=n;i++)
    {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		int cnt=0,t=i;
		for(int j=i-1;j>=1;j--)
		{
			if(c>=a[t]-a[j])
			{
			    c-=a[t]-a[j];
			    cnt++;
			}
		}
		if(cnt>maxn||(cnt==maxn&&m-c<=minn))
		{
			maxn=cnt;
			minn=m-c;
		}
	   	c=m;
	}
	cout<<maxn+1;
    return 0;
}
