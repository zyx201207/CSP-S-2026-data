#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
string a1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=-1e9,s;
	for(ll i=1;i<=n;i++){
		a1[i]=a[i]%=2;
		a[i]/=2;
	}
	for(ll i=n;i>=1;i--){
		maxn=max(maxn,a1);
	}
	cout<<maxn;
	return 0;
}
