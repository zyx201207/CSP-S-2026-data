#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
ll a[MAXN],n,ans,sum[MAXN],maxx;
char c[MAXN];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++) {
		scanf("%lld%s",&a[i],&c[i]);
		maxx=max(a[i],maxx);
	}
	ll l=1,r=n;
	ll nowl=a[1],nowr=a[n];
	while(l<r) {
		if(c[l]!=c[r]) {//²»Ò»Ñù
			if(nowr==nowl) {
				++l,--r;
				ans+=nowl;
				nowl=a[l],nowr=a[r];
			} else if(nowl<nowr) {
				++l;
				ans+=nowl;
				nowr-=nowl;
				nowl=a[l];
			} else {
				--r;
				ans+=nowr;
				nowl-=nowr;
				nowr=a[r];
			}
		} else {
			if(nowr==nowl) {
				++l,--r;
				nowl=a[l],nowr=a[r];
			} else if(nowl<nowr) {
				++l;
				nowr-=nowl;
				nowl=a[l];
			} else {
				--r;
				nowl-=nowr;
				nowr=a[r];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
