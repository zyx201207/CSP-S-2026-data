#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=200050;
ll n,m;
ll a[N];
ll maxx=-1;
vector<ll> v;
ll calc(){
	ll sum=LONG_LONG_MAX;
	for(ll x:v)sum&=x;
	return sum;
}
void A(){
	cout << a[n-m+1];
	return;
}
void dfs(ll p,ll q){
	if(n-q<m-p)return;
	if(p>m){
		maxx=max(maxx,calc());
		return;
	}
	dfs(p,q+1);
	v.push_back(a[q]);
	dfs(p+1,q+1);
	v.pop_back();
	return;
}
void solve(){
	cin >> n >> m;
	bool flag=1;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i-1)flag=0;
	}
	if(n>2000&&flag)A();
	else{
		dfs(1,1);
		cout << maxx;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
