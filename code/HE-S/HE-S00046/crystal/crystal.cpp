#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,lis[500005],delta,ans,same;

int solve(){
	for(int i=1;i<n;i++){
		if(lis[i]+1==lis[i]) {
		same++;
		continue;
		}
		delta+=i*(lis[i+1]-lis[i]);
		if(delta==m) return i+1+same;
		if(delta>m) return i+same;
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> lis[i];
	}
	
	sort(lis+1,lis+n+1);
	ans = solve();
	cout << ans;
}
