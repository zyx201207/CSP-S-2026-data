#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
typedef pair<int,int> pii;
ll n;
ll m;
ll a[N];
ll sum[N];
bool check(ll x){
	for(int i=1;i<=n-x+1;i++){
		int l=i,r=i+x-1;
		
		ll cost=a[r]*x-(sum[r]-sum[l-1]);
		cost=abs(cost);
		//cout<<cost<<'\n';
		if(cost<=m){
			
			return 1;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;

	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		
		sum[i]=sum[i-1]+a[i];
	}
	ll l=0,r=n;
	int ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			//cout<<mid<<'\n';
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
