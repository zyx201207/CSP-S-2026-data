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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	for(ll i = 0;i<n;++i){
		cin>>a[i];
		--a[i];
	}
	vector<ll> dphs;
	for(ll p = 0;p<n;++p){
		vector<ll> ph;
		for(ll i = p;i<n;++i){
			ll cur = a[i];
			vector<ll>::iterator it = find(ph.begin(),ph.end(),cur);
			if(it!=ph.end()){
				ph.erase(it,ph.end());
			}
			ph.emplace_back(cur);
		}
		for(ll i = 0;i<static_cast<ll>(ph.size());++i){
			dphs.emplace_back(ph[i]);
		}
	}
	sort(dphs.begin(),dphs.end());
	for(ll i = 0;i<m-1;++i){
		cout<<(upper_bound(dphs.begin(),dphs.end(),i)-lower_bound(dphs.begin(),dphs.end(),i))<<" ";
	}
	cout<<(upper_bound(dphs.begin(),dphs.end(),m-1)-lower_bound(dphs.begin(),dphs.end(),m-1))<<"\n";
	return 0;
}
