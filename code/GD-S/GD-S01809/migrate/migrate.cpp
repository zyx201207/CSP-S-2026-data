#include<bits/stdc++.h>

using namespace std;
using ll =long long;

ll c,t,n,d,x,ax;
ll a[2000010];
struct node{
	ll d;
	ll num;
}dis[2000010];

void solve(){
	cin >> n >> d;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(i==1)continue;
		if(a[i]-a[i-1]<=d)x=1;
		if(i==2)continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])ax=1;
	}
	if(x==0){
		cout << 0<<endl;
		return;
	}
	else if(ax==0){
		ll sum=a[2]-a[1];
		if(sum*2>d){
			cout << 0 << endl;
			return;
		}
		ll ans=0;
		if(d/sum>n-d/sum){
			cout << 0<<endl;
			return;
		}
		for(ll i=1;i<=n-d/sum-1;i++){
			for(ll j=1;j<d/sum;j++)ans++;
		}
		cout << ans << endl;
		return;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+3;j<=n;j++){
				for(ll k=1;k<=j-i;k++){
					if(a[j]-a[j-k]<=d&&a[j-k]-a[i]<=d&&a[j]-a[j-k-1]<=d&&a[j-k-1]-a[i]<=d&&!(a[j]-a[j-k-3]<=d&&a[j-k-3]-a[i]<=d))ans++;
				}
			}
		}
		cout << ans<<endl;
		return;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)solve(); 
	return 0;
}
