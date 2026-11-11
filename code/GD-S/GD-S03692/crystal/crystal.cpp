#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans,q[N],h=1,t;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int dq=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		dq+=cnt*(a[i]-a[i-1]),cnt++;
		while(dq>m) dq-=a[i]-a[q[h]],h++,cnt--;
		q[++t]=i,ans=max(ans,t-h+1);
	}
	printf("%lld",ans);
	return 0;
}
