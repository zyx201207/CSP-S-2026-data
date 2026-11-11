#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mm,ans,ma=INT_MIN,cj,s=1;
bool f=true,t=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	if(a[i]!=i) f=false;
    	if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) t=false;
	}
	sort(a+1,a+1+n);
	if(f==true)
	{
		for(long long i=0;i<=n;i++)
		{
			m-=i;
			if(m<0) break;
			ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	if(t==true)
	{
		for(long long i=0;i<=n;i++)
		{
			m-=i*a[2]-a[1];
			if(m<0) break;
			ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		ans=0;
		mm=m;
		for(long long j=i;j>=1;j--)
		{
			cj=a[i]-a[j];
			if(cj<=mm)
			{
				mm-=cj;
				ans++;
			}
			if(mm<=0) break;
		}
		ma=max(ma,ans);
	}
	printf("%lld",ma);
	return 0;
}
