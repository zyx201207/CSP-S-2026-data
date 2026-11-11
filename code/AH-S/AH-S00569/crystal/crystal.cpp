#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=5e5;

ll n,m;
ll a[MAXN+5],sum[MAXN+5];

inline ll query(int l,int r) {
    return 1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1]);
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++) {
    	if(a[i]-a[i-1]>m) continue;
    	int l=1,r=i;
    	while(l+1<r) {
    		int mid=(l+r)>>1;
    		if(query(mid,i)<=m) r=mid;
    		else l=mid+1;
		}
		if(l>=1) ans=max(ans,i-l+1);
	} 
	printf("%d",ans);
    return 0;
}
