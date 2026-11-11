#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],k[500010],f[510][510];
vector <int> a[510],t[510];
vector <PII> g[500010];
struct info{
	int a,b;
}qq[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i+m,t[i][j]});
//			cout<<a[i][j]<<" "<<i<<endl;
		}
	}
//	cout<<endl;
	for(int i=1;i<=q;i++){
		cin>>qq[i].a>>qq[i].b;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto tmp:g[i]){
			int y=tmp.fi;y-=m;
			for(auto tmp2:g[i]){
				int y2=tmp2.fi;y2-=m;
				f[y][y2]=min(f[y][y2],tmp.se+tmp2.se);
				f[y2][y]=min(f[y2][y],tmp.se+tmp2.se);
			}
		}
	}
//	cout<<f[1][2]<<endl;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u=qq[i].a,v=qq[i].b;
		int ans=1e18;
		for(auto tmp:g[u]){
			int y=tmp.fi;y-=m;
			for(auto tmp2:g[v]){
				int y2=tmp2.fi;y2-=m;
//				cout<<y<<" "<<y2<<endl;
				ans=min(ans,f[y][y2]+tmp.se+tmp2.se);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
