#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
ll a[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
