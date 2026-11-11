#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL c,t;

void solve(){
	LL n,k;cin >> n >> k;
	vector<LL> g[1000010];
	for(LL i=1;i<=n;i++){
		LL tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		g[tmp1].push_back(tmp2);
		g[tmp2].push_back(tmp1);
	}
	
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		solve();
	}

	return 0;
}

