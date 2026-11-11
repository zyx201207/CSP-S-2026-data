#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
//	int tail=0;
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		for(int j=1;j<=k;j++){
//			int a,t;
//			cin>>a>>t;
//			bel[++tail]=a;
//			inc[a].push_back(tail);
//			if(j>1) G[tail-1].push_back({tail,t});
//		}
//	}
//	for(int i=1;i<=m;i++) for(int j=0;j<(int)inc[i].size();j++) for(int k=0;k<(int)inc[i].size();k++) if(j!=k) G[inc[i][j]].push_back({inc[i][k],});
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<"\n";
	}
	return 0;
}
