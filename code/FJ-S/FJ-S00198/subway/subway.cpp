#include <bits/stdc++.h>
#define int long long
#define rint register int
#define il inline
#define ms memset
using namespace std;
const int inf=2e18;
int c;
int n,m,d,q;
int w[500005];
int f[505][505];
vector<pair<int,int> >v[500005];
signed main(){
//	freopen("subway7.in","r",stdin);
//	freopen("_.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(rint i=1;i<=m;i++){
		cin>>w[i];
	}	
	for(rint i=1;i<=n;i++){
		int len;
		cin>>len;
		for(rint j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(make_pair(i,y));
		}
	}
	ms(f,0x3f,sizeof(f));
	for(rint i=1;i<=m;i++){
		for(auto x:v[i]){
			for(auto y:v[i]){
				if(x==y) continue;
				int u=x.first,v=y.first;
				f[u][v]=min(f[u][v],x.second+y.second);
			}
		}
	}
	for(rint i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(rint k=1;k<=n;k++){
		for(rint i=1;i<=n;i++){
			for(rint j=1;j<=n;j++){
				if(i==j || j==k || i==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		int ans=inf;
		for(auto i:v[x]){
			for(auto j:v[y]){
				ans=min(ans,i.second+j.second+f[i.first][j.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
