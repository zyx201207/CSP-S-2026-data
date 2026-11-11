#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,d,g,b;
	int num;
	cin >> n >> d;
	cin >> g >> b;
	g=(b-g);
	num=d/g;
	for(int i=3;i<=n;i++)	cin >> b;
	int ans=0,t;
	for(int i=1;i<=n;i++){
		t=n-i-num;
		t=t-(t/num);
		if(t<0) continue;
		ans+=t;
	}
	cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	while(t--)	solve();
	
	return 0;
}
