#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],f[N][35],ans;
vector<pair<ll,ll>> v,cur;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		for(ll j=0;j<=30;j++){
			if(a[i]&(1<<j)) f[i][j]=1;
		}
		v.push_back({a[i],i});
	}
	for(ll k=30;k>=0;k--){
		ll cnt=0;
		cur.clear();
		for(auto i:v){
			ll num=i.first,id=i.second;
			if(f[id][k]) cur.push_back(i),cnt++;
		}
		if(cnt>=m){
			ans+=(1<<k);
			v=cur;
		}
	}
	cout<<ans;
	return 0;
}
