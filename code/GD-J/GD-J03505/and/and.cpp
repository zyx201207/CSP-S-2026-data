#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define rep2(x,a,b,c) for(int x=a;b;x-=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const int INF=INT_MAX/3,N=2e5+20;
ll n,ans[40],v[N][40],m,the_ans,flag=0;
vector<ll> ok;
int main() {
	fop("and");
	scanf("%lld%lld",&n,&m);
	rep(i,1,i<=n,1) {
		ll a=0,cnt=0;
		scanf("%lld",&a);
		while(a) {
			v[i][cnt]=a%2;
			a=a>>1;
			cnt++;
		}
	}
//	rep(i,1,i<=n,1){
//		rep(j,0,j<=30,1) cout<<v[i][j];
//		cout<<"\n";
//	}
	rep(i,1,i<=n,1) ok.push_back(i);
	rep2(k,30,k>=0,1) {
		vector<ll> new_ok;
		ll cnt=0;
		for(auto i:ok) if(v[i][k]) new_ok.push_back(i),cnt++;
		if(cnt>=m) {
			ok=new_ok,ans[k]=1,flag=1;
//			for(ll i:ok) cout<<i<<' ';
//			cout<<"\n";
//			for(ll i:ok) cout<<i<' ';
//			cout<<k<<' ';
		} else if(flag) break;
//		cout<<k<<' ';
	}
	ll pow_2=1;
	rep(i,0,i<=30,1) {
		the_ans+=pow_2*ans[i];
//		cout<<ans[i]<<' ';
		pow_2*=2;
	}
	printf("%lld",the_ans);
	return 0;
}

