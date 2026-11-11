#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;

ll n,m,a[N],maxx,k,ans;
bool c[N];

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		maxx=maxx|a[i];
	}
	while(maxx){
		++k,maxx>>=1;
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(ll i=k-1;i>=0;--i){
		ll cnt=0;
		for(ll j=1;j<=n;++j){
			if(!c[j]&&((a[j]>>i)&1))
				++cnt;
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(ll j=1;j<=n;++j)
				if(!c[j]&&!((a[j]>>i)&1))
					c[j]=1;
		}
	}
	
	printf("%lld",ans);
	
	return 0;
}                   
