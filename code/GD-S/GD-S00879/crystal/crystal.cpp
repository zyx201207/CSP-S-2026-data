#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define pref static inline
using namespace std;
using ll=long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vi=vector<int>;
using vl=vector<ll>;using vpi=vector<pii>;using vpl=vector<pll>;using pil=pair<int,ll>;
using vpil=vector<pil>;
namespace my{
	const int N=5e5+5,inf=1e9;
	int n;
	ll m,a[N],sum[N];
	void SOLVE(){
		cin>>n>>m;
		up(i,1,n)cin>>a[i];
		sort(a+1,a+1+n);
		up(i,1,n)sum[i]=sum[i-1]+a[i];
//		up(i,1,n)cout<<sum[i]<<" \n"[i==n];
		int ans=1;
		up(i,1,n){
			ll x=a[i],has=x*i;
			if(has-sum[i]<=m){
				ans=i;
				continue;
			}
			int l=1,r=i,pos=i;
			while(l<=r){
				int mid=(l+r)/2;
//				cout<<i<<' '<<mid<<' '<<1ll*(i-mid+1)*x<<' '<<sum[i]-sum[mid-1]<<'\n';
				if(1ll*(i-mid+1)*x-sum[i]+sum[mid-1]<=m)pos=mid,r=mid-1;
				else l=mid+1;
			}
//			cout<<i<<' '<<pos<<'\n';
			ans=max(ans,i-pos+1);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1;
	//cin>>_;
	while(_--)my::SOLVE();
	return 0;
}
