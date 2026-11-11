#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a,int b) {
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld %lld",&n,&m);
	vector<ll> a(n+1);
	vector<ll> sum(n+1,0);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a.begin()+1,a.end()+1);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	ll zans=sum[n]+m;//15
	//vector<ll> ans(n+1,0);
	ll ans=1;
	for(int i=2;i<=n;i++) {
		ll divide=zans-a[i]*i;
		if(divide>0){
			if(divide==(sum[n]-sum[i])){
				ans=max(ans,i);
			}else{
				continue;
			}
		}else{
			int tans=0;
			while((zans-a[i]*i+tans*a[i])<0) {
				tans++;
			}
			ans=max(ans,i-tans);
		}
	}
	printf("%lld",ans);
	return 0;
}

