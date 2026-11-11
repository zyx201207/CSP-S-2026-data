#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=5e5+7;
int n,m,ans;
int a[maxn],s[maxn];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,pic=i;
		while(l<=r){
			int mid=l+r>>1ll;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) pic=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pic+1);
	}
	printf("%lld",ans);
	return 0;
}
