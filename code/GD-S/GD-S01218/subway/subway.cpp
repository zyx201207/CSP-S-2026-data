#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,p;
ll w[500005],a[55][1000010],t[55][1000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(ll i=0;i<m;i++) cin>>w[i];
	for(ll i=0;i<n;i++){
		ll k;
		cin>>k;
		for(ll j=0;j<k;j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	while(p--){
		ll x,y;
		cin>>x>>y;
		cout<<t[0][0]*(x-y);
	}
	return 0;
}
