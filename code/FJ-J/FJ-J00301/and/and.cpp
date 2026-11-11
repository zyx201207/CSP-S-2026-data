#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll>a;
vector<ll>b;
bool pd(ll s){
	for(int i=0;i<b.size();i++){
		if(s==b[i])return false;
	}
	return true;
}
ll solve(ll x,ll q){
	ll big=0,k;
	if(x==0)return q;
	for(int i=0;i<n;i++){
		if(x==m)b.clear();
		if(pd(a[i])){
			b.push_back(a[i]);
			if(x==m){
				k=solve(x-1,a[i]);	
			}else{
				k=solve(x-1,q&a[i]);
			}
			if(k>big)big=k;
		}
	}
	return big;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	cout<<solve(m,0);
	return 0;
}
