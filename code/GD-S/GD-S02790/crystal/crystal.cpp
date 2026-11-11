#include <bits/stdc++.h>
#define int long long
using namespace std;
int xsx=1e18;
constexpr int N=5e5+7;
int n,m,ans,a[N],pre[N];
int get(int l,int r){
	return pre[r]-pre[l-1];
}
vector<int> tmp;
int check(int idx){
	int l=1,r=idx,ret=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if((idx-mid+1)*a[idx]-get(mid,idx)<=m){
			ret=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return idx-ret+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	printf("%lld\n",ans);
	return 0;
}

