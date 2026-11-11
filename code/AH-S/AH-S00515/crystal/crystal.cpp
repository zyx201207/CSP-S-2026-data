#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=5e5+10;
LL a[N],s[N];
LL n,m;

bool check(int i,int j)
{
	return s[i]-s[j-1]+m>=(i-j+1)*a[i];
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);	
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int maxv=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(i,mid)) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<i<<' '<<ans<<endl;
		maxv=max(maxv,i-ans+1);
	}
	printf("%d",maxv);
	
	return 0;
}
