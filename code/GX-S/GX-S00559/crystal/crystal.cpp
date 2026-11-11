#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=1e6+100;
long long n,m,a[MAXN],re[MAXN],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			re[i]+=a[i]-a[j];
	for(int len=2;len<=n;len++)
	{
		bool flag=true;
		for(int i=1;i<=n-len+1;i++)
			if(re[i+len-1]-re[i]-(a[i+len-1]-a[i-1])*(i-1)<=m)
			{
				ans=len;
				flag=false;
				break;
			}
		if(flag)
			break;
	}
	printf("%lld",ans);
    return 0;
}
