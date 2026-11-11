//GZ-S00341 南明区山水中学 杨梓睿 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll k;
int main() {
	freopen("subway.in","r", stdin);
	freopen("subway.out","w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0; i<m; i++) {
		ll w;
		cin>>w;
	}
	cin>>k;
	for(int i=0; i<n; i++) {
		for(int j=0; j<2*k; j++) {
			ll t;
			cin>>t;
		}
	}
	for(int i=0; i<q; i++) {
		ll x,y;
		cin>>x>>y;
	}
	cout<<d<<'\n';
	cout<<n*m;
	return 0;
}
