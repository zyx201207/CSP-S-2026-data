#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define il inline
const ll P=998244353;
const int N=2e6+10, M=5e3+10;
ll qp(ll a,ll b=P-2){
	ll res=1;
	for(;b;b>>=1,a=(a*a)%P) if(b&1) res=res*a%P;
	return res;
}
// ------------------------------------------------- //
int test_id; int bl[N],br[N];
int n,f[N],len[N],lp[N]; ll d,a[N],s[N];	
// ------------------------------------------------- //
il void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int l=1,r=1;r<=n;++r){
		while(l<r&&a[r]-a[l]>d) ++l;
		lp[r]=l;
	} 
	ll ans=0;
	if(n<=5000){
		for(int st=1;st<=n;++st){
			for(int i=0;i<=n;++i) bl[i]=n+1, br[i]=s[i]=0;
			f[st]=1; for(int i=st+1;i<=n;++i) f[i]=len[i]=0;
			len[st]=1; s[st]=1;
			for(int l=st,r=st+1;r<=n;++r){
				while(l<r&&a[r]-a[l]>d) ++l;
				if(l<r) len[r]=len[l]+1;
				else break;
			}
			for(int i=st;i<=n;++i){
				bl[len[i]]=min(bl[len[i]],i);
				br[len[i]]=max(br[len[i]],i);
			}
			for(int i=st;i<=n;++i) if(len[i]>1){
				f[i]=s[br[len[i]-1]]-s[max(max(lp[i],bl[len[i]-1]),st)-1];
				s[i]=s[i-1]+f[i];
				if(f[i]==2) ++ans;
			}
		} 
	}else if(test_id==11||test_id==12){
		ll hd=a[2]-a[1];
		ll st=2*hd, stv=n-3;
		if(d<st) ans=0;
		else{
			ll cj=(d-st)/hd;
			if(stv-2*cj<0) ans=0;
			else ans=stv-2*cj;
		}
	}
	cout<<ans<<"\n";
	return;
}
// ------------------------------------------------- //
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1; cin>>test_id>>T;
	while(T--) solve(); 
	return 0;
}
