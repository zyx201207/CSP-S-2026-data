#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll a[N];
vector<ll>v;
void solve(ll c){
	ll n,d;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		cout<<0<<endl;
		return;
	}
	if(a[n]-a[1]<=d){
		cout<<0<<endl;
		return;
	}
	if(c<=10){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+3;j<=n;j++){
				v.clear();
				v.push_back(i);
				ll k=i;
				while(k<j){
					ll l=k+1,r=j,res=0;
					while(l<=r){
						ll mid=(l+r)/2;
						if(a[mid]-a[k]<=d){
							res=mid;
							l=mid+1;
						}
						else{
							r=mid-1;
						}
					}
					if(res==0){
						v.clear();
						break;
					}
					v.push_back(res);
					k=res;
				}
				if(v.empty()){
					continue;
				}
				ll py=1;
				for(ll i=0;i<v.size()-2;i++){
					ll j=i+2,mid=i+1;
					ll cnt=1;
					for(ll k=v[mid]-1;k>=max(v[i]+1,v[mid]-2);k--){
						if((a[k]-a[v[i]]<=d)&&(a[v[j]]-a[k]<=d)){
							cnt++;
						}
					}
					py*=cnt;
					if(py>2){
						break;
					}
				}
				if(py==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	else if((c>=11)&&(c<=12)){
		ll ans=0,dd=a[2]-a[1];
		ll l=1,r=n,res=0;
		while(l<=r){
			ll mid=(l+r)/2;
			if((mid-1)*dd<=d){
				res=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		if(res>=3){
			ll mx=res*2-2;
			ans=max(0LL,n-mx+1);
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
}
