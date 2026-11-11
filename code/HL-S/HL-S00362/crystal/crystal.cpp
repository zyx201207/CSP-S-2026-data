#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[501000];
map<ll,ll>f;
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll cnt=0;
	for(ll i=2;i<=n;i++){
		if(cnt+(a[i]-a[i-1])*(i-1)>m){
			cout<<max((m-cnt)/(a[i]-a[i-1])+f[a[i]],i-1)<<"\n";
			return;
		}
		cnt+=(a[i]-a[i-1])*(i-1);
	}
	cout<<n<<"\n";
	return; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}

