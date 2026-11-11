#include<bits/stdc++.h>
using namespace std;
	typedef long long ll;
	const int N=2e5+5;
	ll a[N];
	ll n,m;
	ll ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++){
		ans=a[i-1]&a[i];
	}
	cout<<ans;
	return 0;
}
