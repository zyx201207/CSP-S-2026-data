#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m;
ll a[N];
ll ma=-9e18;
void dfs(ll x,ll step,ll re){
	if(step==m){
		ma=max(re,ma);
		return;
	} 
	for(ll i=x+1;i<n;i++) {
		dfs(i,step+1,re&a[i]);
		//cout<<i<<"->"<<re<<"&"<<a[i]<<"="<<(re&a[i])<<'\n';
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
		
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++){
		dfs(i,1,a[i]);
		//cout<<"------------------------------------------------\n";
	} 
	cout<<ma;
	return 0;
} 
