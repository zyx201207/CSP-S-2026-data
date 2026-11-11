#include<bits/stdc++.h>
using namespace std;
const int e=6e5;
long long n,m,a[e],b[e],mi,ma,ans,k=2,ml,mk,mp,f,mo;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	mi=a[1],ma=a[n];
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	while(k<=n)
	{
		if(ml+b[k]*(k-1)<=m)ml+=b[k]*(k-1),b[1]+=b[k],b[k]=0;
		else
		{
			f=1;
			mo=m-ml;
			mp=(m-ml)/(k-1);
			mk=(m-ml)%(k-1);
			ml=m;
		}
		if(ml==m)
		{
			if(f==0)
			{
				while(a[k+1]==a[k]&&k<n)k++;
				printf("%lld",k);
			}
			else
			{
				long long mm=k-1,md=b[k];
				while(a[k+1]==a[k]&&k<n)k++;
				long long mj=mo/md;
				ans=max(mj+k-mm,mm);
				printf("%lld",ans);
			}
			return 0;
		}
		k++;
	}
	if(k>n)printf("%lld",n);
	return 0;
}
