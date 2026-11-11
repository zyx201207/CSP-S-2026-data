#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll n, m;
ll a[N];
ll qzh[N];
ll cnt[N];
ll ans = -1;
ll ef(ll l, ll r, ll now){
    ll mid = (l+r)/2;
    ll k = m - (now-mid+1)*a[now] + (qzh[now] - qzh[mid-1]);
    //cout<<k<<" "<<l<<" "<<r<<" "<<endl;
    if(l >= r){
	    return now-l+1;
	}
    if(k < 0){
	    return ef(mid+1, r, now);
	}
	else{
	    return ef(l, mid, now);
	}
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++){
	    qzh[i] = qzh[i-1]+a[i];
	    //cout<<qzh[i]<<endl;
	} 
	for (int i=n;i>=1;i--){
	    ans = max(ans, ef(1, i, i));
	    //cout<<ans<<endl;
	}
	cout<<ans;
	return 0;   
} 
