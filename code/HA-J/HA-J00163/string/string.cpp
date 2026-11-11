#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
	ll l;
	ll r;
	ll size;
	char op;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	vector<char> cnt;
	vector<ll> size1;
	char lop1;
	ll size = 0;
	for(ll i = 0; i < n; i++){
		ll a;
		char c1;
		cin >> a >> c1;
		if(i == 0){
			cnt.push_back(c1);
			size1.push_back(a);
		}else{
			if(c1 == lop1){
			    size1[cnt.size() - 1] += a;
				continue;
			}else {
				cnt.push_back(c1);
				size1.push_back(a);
			}
		}
		lop1 = c1;
	}
	ll ans = 0;
	ll zzz = cnt.size();
	vector<node> c(zzz);
	ll id = 0;
	for(ll i = 0; i < zzz; i++){
		size += size1[i];
		c[i].l = id;
		id += size1[i] - 1; 
		c[i].r = id;
		c[i].op = cnt[i];
		c[i].size = size1[i];
		id++;
	}
	ll ld = 0 , rd = size - 1;
	while(ld < rd){
		ll x , y;
		for(ll i = 0; i < zzz; i++){
			if(c[i].l <= ld && c[i].r >= ld){
				x = i;
			}
			if(c[i].l <= rd && c[i].r >= rd){
				y = i;
			}
		}
		if(c[x].op == c[y].op){
			ans += abs(c[x].size-c[y].size);
			ld = ld + min(c[x].size , c[y].size);
			rd = rd - min(c[x].size , c[y].size);
			if(c[x].size > c[y].size){
				c[x].size -= min(c[x].size , c[y].size);
			}else if(c[x].size < c[y].size){
				c[y].size -= min(c[y].size , c[x].size);
			}
		}else {
			ans += min(c[x].size , c[y].size);
			ld = ld + min(c[x].size , c[y].size);
			rd = rd - min(c[x].size , c[y].size); 
			if(c[x].size > c[y].size){
				c[x].size -= min(c[x].size , c[y].size);
			}else if(c[x].size < c[y].size){
				c[y].size -= min(c[y].size , c[x].size);
			}
		}
	}
	
	cout << ans;
	return 0;
}
