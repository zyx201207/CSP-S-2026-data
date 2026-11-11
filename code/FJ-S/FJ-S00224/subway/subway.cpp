#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,b,t,w[500001],p[500001];
long long f[501][501],s;
pair<int,int>g[500001][21];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c;
		while(c--){
			cin>>a>>t;
			p[a]++;
			g[a][p[a]]=make_pair(i,t);
		}
		for(int j=1;j<=n;j++){
			f[i][j]=LONG_LONG_MAX/501;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int u=1;u<=p[i];u++){
			for(int v=u+1;v<=p[i];v++){
				f[g[i][u].first][g[i][v].first]=min(f[g[i][u].first][g[i][v].first],1ll*g[i][u].second+g[i][v].second);
				f[g[i][v].first][g[i][u].first]=f[g[i][u].first][g[i][v].first];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		cin>>a>>b;
		s=LONG_LONG_MAX;
		for(int u=1;u<=p[a];u++){
			for(int v=1;v<=p[b];v++){
				s=min(s,w[a]+w[b]+f[g[a][u].first][g[b][v].first]+g[a][u].second+g[b][v].second);
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
