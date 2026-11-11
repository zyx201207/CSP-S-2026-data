#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001];
long long s[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	  s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,tmp=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			long long sum1=s[i]-s[mid-1];
			if(a[i]*(i-mid+1)-sum1<=m)r=mid-1,tmp=min(tmp,mid);
			else l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans<<'\n';
	return 0;
}
