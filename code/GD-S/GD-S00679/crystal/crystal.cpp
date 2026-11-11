#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define int long long
#define pii std::pair<int,int>
#define rep(x,qwq,qaq) for(int (x)=(qwq);(x)<=(qaq);++(x))
#define per(x,qwq,qaq) for(int (x)=(qwq);(x)>=(qaq);--(x))
const int N=5e5+7;
int n,ans;
ll a[N],s[N],m;
bool ck(int l,int r){
	ll cnt=s[r]-s[l-1],res=(r-l+1)*a[r];
	return (res-cnt)<=m;
}
void solve(){
	std::cin>>n>>m;
	rep(i,1,n) std::cin>>a[i];
	std::sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i]; 
//	rep(i,1,n){
//		int cnt=0,res=0;
//		per(j,i,1){
//			cnt+=a[i]-a[j];
//			if(cnt>m) break;
//			res++;
////			std::cout<<i<<' '<<cnt<<' '<<res<<'\n';
//		}
//		ans=std::max(ans,res);
//	}
	rep(i,1,n){
		int l=1,r=i,mid,t=0;
		while(l<=r){
			mid=(l+r)/2;
			if(ck(mid,i)){
				t=mid;
				r=mid-1;
			} 
			else l=mid+1;
//			std::cout<<i<<' '<<l<<' '<<r<<'\n';
		}
		ans=std::max(ans,(i-t+1));
	}
	std::cout<<ans<<'\n';
} 
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	std::cin>>T;
	while(T--) solve();
	return 0;
}
/*
5 5
1 2 4 8 9

*/
