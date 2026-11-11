#include <bits/stdc++.h>
using namespace std;
const int N=500005;
bool cmp(long long a,long long b)
{
	return a<b;
}
long long a[N];
long long sum[N];
long long cnt[N];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--)
	{
		if(i<=ans) continue;
		int r=i-1,l=1;
		while(l<r)
		{
			int mid=(r+l)>>1;
			if(abs(sum[i-1]-sum[mid-1]-(i-mid)*a[i])<=m) r=mid;
			else l=mid+1;
		}
		cnt[i]=i-l+1;
		ans=max(cnt[i],ans);
	}
	printf("%lld",ans);
	return 0;
} 
