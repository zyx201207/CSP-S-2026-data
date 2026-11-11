#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],qz[N];
int ef(int l,int r,int st)
{
	int res=st;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		ll tmp=(ll)st-mid+1ll;
		tmp=(ll)tmp*a[st]-(qz[st]-qz[mid-1]);
		if(tmp<=m) res=st-mid+1,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,ef(1,i,i));
//		printf("%d   %d\n",i,ef(1,i,i));
	}
	printf("%d",ans);
	return 0;
}
