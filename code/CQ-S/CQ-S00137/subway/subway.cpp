#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
typedef long long ll;
const int M=5e5+5;
const int N=505;
const ll inf=1e18;
int C,n,m,d,q,q1,q2;
int k,x;
ll y,w[M],g[N][N],ans;
vector<pair<int,ll> > mp[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	I C >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) I w[i];
	for(int i=1;i<=n;i++){
		I k;
		for(int j=1;j<=k;j++){
			I x >> y;
			mp[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=inf;
		g[i][i]=0;
	}
	int l=0;
	pair<int,ll> rt1,rt2;
	for(int i=1;i<=m;i++){
		l=mp[i].size();
		for(int a=0;a<l;a++){
			for(int b=a+1;b<l;b++){
				rt1=mp[i][a],rt2=mp[i][b];
				g[rt1.first][rt2.first]=min(g[rt1.first][rt2.first],rt1.second+rt2.second);
				g[rt2.first][rt1.first]=min(g[rt2.first][rt1.first],rt1.second+rt2.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
	while(q--){
		I q1 >> q2;
		ans=inf;
		int l1=mp[q1].size(),l2=mp[q2].size();
		for(int i=0;i<l1;i++){
			for(int j=0;j<l2;j++) ans=min(ans,w[q1]+w[q2]+g[mp[q1][i].first][mp[q2][j].first]+mp[q1][i].second+mp[q2][j].second);
		}
		O ans << "\n";
	}
	return 0;
}
