#include<bits/stdc++.h>
# define Maxn 500005
# define ll long long
using namespace std;
int n,ans;ll m;
ll a[Maxn],d[Maxn];

int main() {
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	
	for(int i=1;i<=n;i++) {
		int l=1,r=i,mid,p=0;
		while(l<=r) {
			mid=(l+r)>>1;
			if((ll)(i-mid+1)*a[i]-(d[i]-d[mid-1])<=m) p=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,p);
	}
	printf("%d\n",ans);
	return 0;
}
