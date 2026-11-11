#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
ll w[510],a[500010],t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<ll> vt[500010];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		ll k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
			vt[i].push_back(a[i]);
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		
	}
	return 0;
}
