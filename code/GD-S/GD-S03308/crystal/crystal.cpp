#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<ll>a(n+5,0);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	for(ll i=2;i<=n;i++){
		ll c=m;
		ll ans1=1;
		for(ll j=i-1;j>=1;j--){
			if(c>=a[i]-a[j])c-=a[i]-a[j],ans1++;
			else break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}

