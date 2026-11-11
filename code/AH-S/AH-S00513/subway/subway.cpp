#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define vint vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
const int N=500010,M=510;
int c,n,m,d,q,a[N],k[N],dis[M][M];
vii e[N];
signed main(){
	//~ int cl=clock();
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,tim;j<=k[i];j++){
			cin>>x>>tim;e[x].push_back({i,tim});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			for(int k=j+1;k<(int)e[i].size();k++){
				dis[e[i][j].first][e[i][k].first]=min(dis[e[i][j].first][e[i][k].first],
													  e[i][j].second+e[i][k].second);
				dis[e[i][k].first][e[i][j].first]=min(dis[e[i][k].first][e[i][j].first],
													  e[i][k].second+e[i][j].second);
			}
		}
	}
	//~ for(int i=1;i<=n;i++){
		//~ for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
		//~ cout<<'\n';
	//~ }
		
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		int ans=1e18;
		for(int j=0;j<(int)e[u].size();j++){
			for(int k=0;k<(int)e[v].size();k++){
				ans=min(ans,dis[e[u][j].first][e[v][k].first]+e[u][j].second+e[v][k].second);
			}
		}cout<<ans+a[u]+a[v]<<'\n';
	}
	//~ cerr<<1.0*(clock()-cl)/CLOCKS_PER_SEC;
}
/*
 diff -b subway.out subway3.ans
 * */
