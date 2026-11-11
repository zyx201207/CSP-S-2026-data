#include<bits/stdc++.h>
using namespace std;
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) {
		int n,k;
		cin>>n>>k;
		for(int x,y,i=1;i<n;i++) cin>>x>>y;
		cout<<(n-k)/3;
	}
	return 0;
}
