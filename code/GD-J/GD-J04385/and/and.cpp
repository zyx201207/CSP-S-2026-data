#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+5;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
