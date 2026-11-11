#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5;
ll a[MAXN+5];
// O(n^m) 50' (1~10)
ll tdeep(ll n,ll m,ll depth,ll st,ll value){
	if(depth>m)return value;
	ll maxans=0;
	for(int i=st;i<n;i++){
		maxans=max(maxans,
		tdeep(n,m,depth+1,i+1,value&a[i]));
	}return maxans;
}
// O(m+n) Special 10' (14~15) 
ll p14(ll n,ll m){
	m--;
	ll ans=a[n-1];
	for(int i=0;i<m;i++){
		ans-=(1<<i);
	}return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	bool check14=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i-1)check14=0;
	}
	if(check14){
		cout<<p14(n,m);
		return 0;
	}
	cout<<tdeep(n,m,1,0,LONG_LONG_MAX);
}
