#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,xx=0,ans=-1,ans1=0,x ;
	cin>>n>>m;
	vector<ll> a(N);
	for(ll i=1;i<=n;i++) {
	  cin>>a[i];
	  xx+=a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	for(ll i=2;i<=n;i++){
		ans1=0,x=m;
		for(ll j=i-1;j>=1;j--){
			x-=(a[i]-a[j]);
			ans1++;
			if(x<=0) break;
		}
		ans=max(ans1+1,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 
