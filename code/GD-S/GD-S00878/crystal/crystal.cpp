#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5,mod=1e9+7;
ll a[maxn],s[maxn];
ll n,m;
bool check(ll mid){
	for (int i=1;i<=n-mid+1;i++) if (a[i+mid-1]*mid-s[i+mid-1]+s[i-1]<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=0;
	ll l=1,r=n;
	while (l<=r){
		ll mid=(l+r)>>1;
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	if (ans==1) cout<<0;
	else printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

