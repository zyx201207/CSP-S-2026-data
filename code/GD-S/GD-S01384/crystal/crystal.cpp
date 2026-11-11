#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,ans;
ll a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++)
	{
		while(l<r&&s[r]-s[l-1]+m<a[r]*((r-l+1ll)*1ll)) l++;
		if(l!=r&&s[r]-s[l-1]+m>=a[r]*((r-l+1ll)*1ll)) ans=max(ans,r-l+1ll);
	}
	printf("%lld",ans);
	return 0;
}
