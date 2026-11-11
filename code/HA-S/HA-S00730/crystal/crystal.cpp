#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],b[100001];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll t=0,ans=0;
	for(ll i=2;i<=n;i++){
		ans=b[a[i-1]];
		ll t1=(a[i]-a[i-1])*b[a[i-1]];
		if(a[i]==a[i-1]) continue;
		if(t+t1>m){
			break;
		}else{
			t+=t1;
			b[a[i]]+=b[a[i-1]];
//			cout<<i<<" "<<t<<" "<<b[a[i]]<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
