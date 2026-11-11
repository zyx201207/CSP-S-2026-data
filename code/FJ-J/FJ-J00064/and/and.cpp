#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<int>::max(),NEG_INF = numeric_limits<int>::lowest();
ll ans = NEG_INF;
ll n,m;
vector<ll> a;
void dfs(ll x,ll i,ll num){
	if(x>=m){
		for(;i<n;++i){
			ans = max(ans,(num&a[i]));
		}
		return;
	}
	for(;i<n;++i){
		dfs(x+1,i+1,(num&a[i]));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	vector<ll> prev(n+1,INF),re_prev(n+1,INF);
	for(ll i = 0;i<n;++i){
		cin>>a[i];
		prev[i+1] = (prev[i]&a[i]);
	}
	if(n<=2000){
		dfs(1,0,INF);
		cout<<ans<<"\n";
	}else{
		if(m==n-1){
			for(ll i = n-1;i>=0;--i){
				re_prev[i] = (re_prev[i+1]&a[i]);
			}
			for(ll i = 0;i<n;++i){
				ans = max(ans,(prev[i]&re_prev[i+1]));
			}
			cout<<ans<<"\n";
		}else{
			ll sum = INF;
			for(ll i = n-1;i>=n-m;--i){
				sum &= a[i];
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}
