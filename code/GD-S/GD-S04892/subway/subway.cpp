#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q,w[505],k[500005];
struct road{
	int station,time;
};

int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<road> a[505];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			int e,t;
			cin>>e>>t;
			a[i].push_back({e,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y]+a[n][4].time;
		cout<<ans<<'\n';
	}
	return 0;
} 
