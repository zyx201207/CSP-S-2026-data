//GZ-S00317
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
random_device rnd;
mt19937 rd(rnd());
const int N=5e5+9;
ll n,m,a[N],pre[N],ans=1;
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		ll l=1,r=i,p=-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m){
				p=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(p>0){
			ans=max(ans,i-p+1);
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}

