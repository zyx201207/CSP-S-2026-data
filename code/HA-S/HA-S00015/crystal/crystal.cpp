#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(ll a,ll b){
	return a<b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1,0);
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),cmp);
	for(ll i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	
	ll ans=0;
	
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		ll val=a[i]-a[i-1];
		while(l<r){
			ll mid=(l+r)>>1;
			ll tot=(i-mid+1)*val-(a[i]-a[mid-1]);
			//cout<<tot<<endl;
			if(tot>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		if((i-l+1)>ans)	ans=(i-l+1);
	}
	
	cout<<ans;
	
	return 0;
}