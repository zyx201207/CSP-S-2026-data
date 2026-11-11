#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans,qz[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=i&&a[i]*(i-j+1)-(qz[i]-qz[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
