#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ll n , m;
	cin >> n >> m;
	vector<ll> a;
	for(ll i = 0; i < n; i++){
		ll a1;
		cin >> a1;
		a.push_back(a1);	
	}
	vector<ll> ans(m + 1 , 0);
	set<ll> s;
	queue<ll> q;
	for(ll k = 0; k < m; k++){
		s.insert(a[k]);
		for(ll i = k; i < a.size(); i++){
		    q.push(a[i]);
		    if(s.count(a[i])){
		    	s.empty();
		    	s.insert(a[i]);
			    for(ll j = k; j < i; j++){
				    q.pop();
			    }
		    }else s.insert(a[i]);
		}
		while(!q.empty()){
		    ll a = q.front();
		    q.pop();
		    ans[a]++;
	    }
	}
	
	for(ll i = 1; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
