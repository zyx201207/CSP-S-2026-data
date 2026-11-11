#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1; 
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

3

250383992
293238795
*/

