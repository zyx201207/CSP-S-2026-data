#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],n,ans=LLONG_MIN;
bool b[200010];
ll ccf(ll m,vector<ll> noi){
	if(m<=0){
		ll gesp=noi[1];
		for(int i=1;i<(int)noi.size();i++) gesp&=noi[i];
		return gesp;
	}
	ll csp=LLONG_MIN;
	for(int i=1;i<=n;i++){
		noi.push_back(a[i]);
		csp=max(ccf(m-1,noi),csp);
		noi.pop_back();
	}
	return csp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	vector<ll> noip;
	cout<<ccf(m,noip)<<endl;
	return 0;
}

