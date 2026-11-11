#include<bits/stdc++.h>


using namespace std;
typedef long long ll;



const ll MM = 500006;
ll n,m;
ll a[MM],s[MM],ans=0;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	//cout<<"/"<<endl;
	for(ll i=1;i<=n;i++)cin>>a[i];
	a[0]=0,s[0]=0;
	s[1] = a[1];
	sort( a+1,a+n+1 );
	for(ll i=1;i<=n;i++){
		s[i] = a[i] + s[i-1];
		
	}
	//cout<<'/'<<endl;
	
	
	for(ll i=1;i<=n;i++){
		ll l = 1,r = i;
		while(l<r){
			ll mid = (l+r)/2;
			if(a[i]*(i-mid+1) - (s[i]-s[mid-1]) > m ) l=mid+1;
			else r = mid;
			//cout<<l<<" "<<r<<endl;
		}
		//cout<<i-l+1<<" / "<<a[i]*(i-l+1) - (s[i]-s[l-1])<<endl;
		ans = max(ans , i-l+1);
	}
	ll ttt=0;
	
	
	cout<<ans<<endl;
	return 0;
}
