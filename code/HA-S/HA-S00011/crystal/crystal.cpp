#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;
vector<ll> a;
ll z;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>z;
		a.push_back(z);
	}
	ll l = 0,r = 0;
	ll ans = 0;
	ll sum = 0;
	sort(a.begin(),a.end());
	a.push_back(0);
	while(r != n){
		if(sum > m){
			sum -= a[r]-a[l];
			l++;
		}
	    ans = max(ans,r-l+1);
	    if(sum <= m){
	    	sum += (a[r+1]-a[r])*(r-l+1);
			r++;
	    }
	}
	cout<<ans;
	return 0;
}

