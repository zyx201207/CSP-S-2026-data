#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e12+10;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n, m;
	cin>>n>>m;
	vector<ll>arr(n+1, 0);
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	arr[0]=-INF;
	sort(arr.begin(), arr.end());
	ll l=1, r=1;
	ll cost=0;
	ll res=1;
	ll maxres=1;
	while(l<=r&&r<=n){
		ll nc=(arr[r+1]-arr[r])*(r-l+1);
		if(cost+nc<=m){
			cost+=nc;
			r++;
			res++;
			maxres=max(maxres, res);
		}else{
			cost-=arr[r]-arr[l];
			l++;
			res--;
			maxres=max(maxres, res);
		}
	}
	cout<<maxres<<'\n';
	return 0;
}
