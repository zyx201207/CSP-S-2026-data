#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i) 
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+10;

int n,res;
ll m,a[maxn],s[maxn];

inline bool check(int l,int r){
	ll sum=-(s[r]-s[l-1])+1ll*(r-l+1)*a[r];
	return sum<=m; 
}

inline void solve(){
	scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	rep(i,1,n){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		res=max(res,i-r+1);
	}
	printf("%d",res); 
} 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
//	scanf("%d",&_);
	while(_--) solve();
}
