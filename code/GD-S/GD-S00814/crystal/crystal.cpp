#include<bits/stdc++.h>
#define int long long
using namespace std;
int T=1,ans,n,m,a[500010],sum[500010];
void op(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int work(int k){
	int l=1,r=k-1,an=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int num=(k-mid)*a[k]-(sum[k-1]-sum[mid-1]);
		if(num<=m) r=mid-1,an=k-mid+1;
		else l=mid+1;
	}
	return an;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,work(i));
	cout<<ans;
}
signed main(){
	op();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	while(T--){
		solve();
	}
}
