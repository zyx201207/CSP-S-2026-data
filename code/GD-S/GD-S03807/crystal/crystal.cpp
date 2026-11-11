#include<bits/stdc++.h>
#define int long long
#define MAXN 1000005
using namespace std;
int a[MAXN],n,m,ans,sum,b[MAXN],l,r,q[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);l=1,r=0;
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	for(int i=1;i<=n;i++){
		r++;
		while(l<=r&&a[i]*(r-l+1)-(b[r]-b[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}

