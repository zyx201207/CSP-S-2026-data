#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	
	ll cnt=0;
	
	ll val=a[1]-a[0];
	
	vector<ll>adj;
	adj.push_back(0);
	
	ll group=m/val;
	
	for(ll i=0;i<m/val+1;i++){
		if(group>n){
			cnt=n-group%n;
		}else{
			if(i!=0) adj.push_back(adj[i-1]+i);
			if(adj[i]<=group) cnt=i;
		}
	}
	
	cout<<cnt+1;
	
	return 0;
} 
