#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=5e5+5;

int n;

ll m,a[MAXN],sum[MAXN];

inline bool check(int checknum){
	for (int i=checknum;i<=n;i++){
		if (a[i]*checknum-(sum[i]-sum[i-checknum])<=m) return true;
	}
	return false;
}

inline void prework(){
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	return;
}

inline void solve(){
	int l=1,r=n,ans=1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	prework();
	solve();
	return 0;
} 
