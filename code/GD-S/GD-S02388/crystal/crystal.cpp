#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
ll n,m;
ll a[N];
ll mn = 100000000000000010;
ll num,ans=1;
void solve_1(ll cnt){
	ll id = 0;
	cnt /= n;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		if(abs(a[i]-cnt) <= mn){
			num = a[i];
			id = i;
			mn = abs(a[i]-cnt);
		}
	}
	ll cnt2 = 0,m1=m;	
	for(int i = id-1;i >= 1;i--){
		if(m1 >= (num-a[i])){
			m1-=(num-a[i]);
			ans++;
		}
		if(m1==0) break;
	}
	printf("%lld",ans);
	return;
}
void solve_2(){
	ll m1 = m;
	ll an = a[n];
	for(ll i = n-1;i >= 1;i--){
		ll sub = abs(an-a[i]);
		if(m1>=sub){
			m1 -= sub;
			ans++;
		}
		if(m1 == 0) break;
	}
	printf("%lld",ans);
	return;
}
void solve(){
	ll cnt = 0;
	scanf("%lld%lld",&n,&m);
	ll mx = -1;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) mx = max(mx,abs(a[i]-a[i-1]));
	if(mx == 1){
		solve_2();
	}
	else if(n<=20&&a[n]<=20){
		if(m >= 380) cout<<n;
		else{
			solve_1(cnt);
		}
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

