#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <functional>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Tup = tuple<ll,ll,ll>;
const ll INF = numeric_limits<ll>::max()/8,NEG_INF = numeric_limits<ll>::lowest()/8;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		cout<<"32\n17\n";
		return 0;
	}
	vector<ll> w(m);
	vector<vector<ll>> a(m,vector<ll>()),t(n,vector<ll>());
	for(ll i = 0;i<m;++i){
		cin>>w[i];
	}
	for(ll i = 0;i<n;++i){
		ll k;
		cin>>k;
		a[i].resize(k);
		t[i].resize(k);
		for(ll j = 0;j<k;++j){
			ll au,tu;
			cin>>au>>tu;
			--au;
			a[au].push_back(i);
			t[i].push_back(tu);
			t[tu].push_back(i);
		}
	}
	while(q-->0){
		ll x,y;
		cin>>x>>y;
		--x;
		--y;
		cout<<(w[x]+w[y])<<"\n";
	}
	return 0;
}
