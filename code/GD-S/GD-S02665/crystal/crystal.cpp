#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,l,m,rec,ans;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	l=1;
	ans=1; 
	for(int i=2;i<=n;i++)
	{
		while(l<i&&(a[i]-a[i-1])*(i-l)+rec>m)
		{
			rec-=a[i-1]-a[l];
			l++;
		}
		rec+=(a[i]-a[i-1])*(i-l);
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
