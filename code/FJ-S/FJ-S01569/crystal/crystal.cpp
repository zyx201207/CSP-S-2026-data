#include<bits/stdc++.h>
#define ll long long
using namespace std;

int getmin(vector<ll> a,ll n){
	int ret = 0;
	ll lstc = 0;
	
	for(ll i = 0; i < n; i++){
		ll count = 0;
		for(ll j = 0; j < n; j++){
			count += abs(a[i] - a[j]);
		}
		if(!lstc || count < lstc){
			lstc = count;
			ret = i;
		}
	}
	return ret;
}

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+10);
	for(ll i = 0; i < n; i++)cin>>a[i];
	//printf("%d",getmin(a,n));
	int t = getmin(a,n);
	vector<ll> dis(n+10);
	for(ll i = 0; i < n; i++){
		dis[i] = abs(a[i] - a[t]);
		//cout<<dis[i]<<" ";
	}
	sort(dis.begin(),dis.begin() + n);
	//for(ll i = 0; i < n; i++)cout<<dis[i]<<" ";
	ll i = 0;
	for(i; i < n; i++){
		if(m <= 0)break;
		if(m < dis[i])break;
		m -= dis[i];
		
		
	}
	cout<<i;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
