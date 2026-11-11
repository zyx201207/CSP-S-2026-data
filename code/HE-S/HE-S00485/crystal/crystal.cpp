#include <bits/stdc++.h>
using namespace std;
void OI(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
void testOI(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
}
typedef long long ll;
const int N=5e5+5;
int n,ans=1;
ll m,a[N],sum[N];
void solve(){
	int l=1,r=1;
	for(;r<=n;r++){
		for(;l<r&&1ll*(r-l)*a[r]-sum[r-1]+sum[l-1]>m;)
			l++;
		ans=max(ans,r-l+1);
	}
}
int main(){
	OI();
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	solve();
	printf("%d",ans);
	return 0;
}


