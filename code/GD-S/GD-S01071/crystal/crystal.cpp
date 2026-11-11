#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
const int inf=(1e12);
int sm[500005];
signed main()
{
//	freopen("crystal1.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
//		a[i]+=inf;
	}
//	cout<<n<<" "<<m<<endl<<endl;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n,mid,anss=i;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[mid]*(mid-(i)+1)-(sm[mid]-sm[i-1])<=m) anss=max(anss,mid),l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,anss-i+1);
	}
	printf("%lld",ans);
} 
