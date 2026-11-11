#include <bits/stdc++.h>
using namespace std;
int w[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<pair<int,int> > g[n+1];
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			g[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		
	}
	return 0;
}
