#include<bits/stdc++.h>

using namespace std; 
typedef long long ll;
const ll N =510;
ll n, m, c, d, q;
ll w[N],a[N][N],t[N][N];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >>c >>n>>m>>d>>q;
	for(ll i=1; i<= m; ++i){
		cin >> w[i];
	}
	
	ll k;
	for(ll i=1; i<=n;++i){
		cin >> k;
		for(ll j=1; j<=k;++j){
			cin >> a[i][j]>>t[i][j];
		}
	}
	
	ll l, r;
	while(q--){
		cin>>l>>r;
		cout<<'a';
	}

	cout<<0;
	
	return 0;

}
