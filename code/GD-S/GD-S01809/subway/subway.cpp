#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool x;
ll c,n,m,d,q;
ll w[500010];

void solve(){
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=n;i++){
		cin >> w[i];
		w[i]+=w[i-1];
	}
	cout << w[n]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
