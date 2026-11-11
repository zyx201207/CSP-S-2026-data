#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m;
ll a[N];
ll check(ll l,ll s){
	ll cnt=1,now_m=m;
	for(ll i=l-1;i>=1;i--){
		if(s-a[i]<=now_m){
			cnt++;
			now_m-=s-a[i];
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	ll ans=-1;
	if(n<=5000){
		for(ll i=n;i>=1;i--){
			ans=max(ans,check(i,a[i]));
		}
		cout<<ans;	
	}
	else{
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=i){flag=0;break;}
		}
		if(flag==1){
			ll ans=0;
			ll now_m=0;
			for(ll i=1;i<=n;i++){
				if(now_m+i<=m){
					ans++;
					now_m+=i;
				}
			}
			cout<<ans;
		}
		else{
			ll ans=0;
			ll now_m=a[2]-a[1];
			ll d=a[2]-a[1];
			for(ll i=1;i<=n;i++){
				if(now_m+d*i<=m){
					ans++;
					if(i==1)continue;
					now_m+=d*i;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
