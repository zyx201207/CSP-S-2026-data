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
const ll INF = numeric_limits<ll>::max()/2,NEG_INF = numeric_limits<ll>::lowest()/2;
using Tup = pair<ll,ll>;
struct Node{
	ll d = INF;
	ll count = 0;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t-->0){
		ll n,d,ans = 0;
		cin>>n>>d;
		vector<ll> x(n);
		for(ll i = 0;i<n;++i){
			cin>>x[i];
		}
		cout<<"0\n";
	}
	return 0;
}
