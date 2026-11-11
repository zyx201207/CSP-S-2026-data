#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	long long k=0;
	for(int i=n,j=n;i>=1&&j>=1;)
	{
		if(j-1>0&&k+a[i]-a[j-1]<=m)k+=a[i]-a[j-1],j--;
		else k-=(a[i]-a[i-1])*(i-j),i--;
		if(i-j+1>ans)ans=i-j+1;
	}
	if(ans==0)ans=1;
	printf("%lld",ans);
}
