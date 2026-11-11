#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll N=5e5+5;
int n;
ll m,a[N],sum[N];
map<ll,ll> mp1,mp2;
ll ans,tot;
ll cnt[N];
ll calc(ll x,ll pos){
	ll l=1,r=pos-1,res=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if((sum[mid]-sum[pos])+m>=(pos-mid)*x){
			r=mid-1;
			res=max(res,pos-mid);
		}
		else{
			l=mid+1;
		}
	}
	return res;
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(!mp2[a[i]]){
			mp2[a[i]]=++tot;
			cnt[tot]=i;
		}
		mp1[a[i]]++;
	}
	for(int i=n;i;i--){
		sum[i]=sum[i+1]+a[i];
	}
	
	/*for(int i=1;i<=n;++i){
		cout << i << " " << a[i] << " " << mp1[a[i]] << " " << mp2[a[i]] << " " << cnt[mp2[a[i]]] <<  '\n';
	}*/
	for(int i=1;i<=n;++i){
		if(cnt[mp2[a[i]]]==i)ans=max(ans,calc(a[i],i)+mp1[a[i]]);
		else ans=max(ans,calc(a[i],i));
		//cout << ans << " " << i  << " " << a[i] << " " <<  (cnt[mp2[a[i]]]==i)  << '\n';
	}
	cout << ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
} 
