#include <bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,Q;
pair<int,int> p[500005][21];
int len[500005];
int w[500005]; 
int F[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			p[a][++len[a]]=make_pair(i,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			F[i][j]=(i==j?0:1e18);
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<=len[i];l++){
			for(int r=l+1;r<=len[i];r++){
				F[p[i][l].first][p[i][r].first]=min(F[p[i][l].first][p[i][r].first],p[i][l].second+p[i][r].second);
				F[p[i][r].first][p[i][l].first]=min(F[p[i][r].first][p[i][l].first],p[i][l].second+p[i][r].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
			}
		}
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		int ans=1e18;
		for(int i=1;i<=len[l];i++){
			for(int j=1;j<=len[r];j++){
				ans=min(ans,F[p[l][i].first][p[r][j].first]+p[l][i].second+p[r][j].second);
			}
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
