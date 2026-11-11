#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5E5+5;
ll a[N],s[N],fd[N],fs[N];
ll n,m,ans;
bool chk(ll len){
	if(len == 1){
		return true;
	}
	bool flag = false;
	for(ll i = 1;i <= n-len+1;i++){
		ll j = i+len-1;
		ll sum = (fs[j-1]-fs[i-1])-((a[j]-a[i])*(j-len));
		if(sum <= m){
			flag = true;
		}
	}
	return flag;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i = 1;i < n;i++){
		fd[i] = (a[i+1]-a[i])*i;
		s[i] = s[i-1]+a[i];
		fs[i] = fs[i-1]+fd[i];
	}
	ll l = 1,r = n;
	while(l <= r){
		ll mid = (l+r)/2;
		if(chk(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}
