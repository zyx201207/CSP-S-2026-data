#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int c,t,n,k;
vector<int> G[N];

bool chk(int x){
	int d = x+1;
	int cnt = 1;
	while(cnt <= k){
		d += (x*2+1);
		cnt++;
	}
	if(d >= n-x) return 1;
	return 0;
}

void sol(){
	int l = 1,r = n-1;
	int ans = n;
	while(l < r){
		int mid = (l+r)/2;
		if(chk(mid)) r = mid,ans = min(ans,mid);
		else l = mid+1;
	}
	cout << ans << endl;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	cin >> c >>  t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		sol();
	}
	return 0;
}
