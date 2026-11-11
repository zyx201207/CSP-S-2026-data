#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e6+10;
constexpr ll INF=1e18;
ll n,m,ans; 
vector<ll> a,p,d;
void solve(){
	cin>>n>>m;
	a.resize(n+1);
	p.resize(n+1);
	d.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		p[i]=d[i]+d[i-1];
	}
	ll l=1,r=1;
	ll sum=0,ans=0;
	while(l<=n && r<=n){
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
			sum+=(r-l)*d[r];
		}else{
			sum=sum-p[r]+p[l];
			l++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}

