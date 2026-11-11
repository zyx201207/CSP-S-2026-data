#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ma;ll n,m;
ll a[200005];
ll cnt=0;
ll dfs(ll x){
	if(x>m || x>=n-1){
		return ma;
	}
	for(ll i=x;i<=n;i++){
		if(ma < (ma&a[i])){
			ma = (ma&a[i]);
		}
		if(i==n){
			dfs(x+1);
		}else{
			dfs(x);
		}
		
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ma=a[1];
	for(int i=1;i<=m;i++){
		ma=(ma & a[i]);
	}
	cout<<dfs(0);
	return 0;
}












































  



































