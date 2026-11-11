#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5,M=505;
int c,n,m,d,q;
int e[M][M];
int sud[N];
vector<pair<int ,int> > st[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sud[i];
	}for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int a,tim;
			cin>>a>>tim;
			st[a].push_back({i,tim});
		}
	}memset(e,0x3f,sizeof(e));
	for(int i=1;i<=n;i++){
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			for(int k=0;k<st[i].size();k++){
				int u=st[i][j].first;
				int v=st[i][k].first;
				if(k==j) continue;
				e[u][v]=min(e[u][v],st[i][j].second+st[i][k].second);
				e[v][u]=e[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=1e18+5;
		for(int j=0;j<st[u].size();j++){
			for(int k=0;k<st[v].size();k++){				
				int x=st[u][j].first;
				int y=st[v][k].first;
				int res=e[x][y]+st[u][j].second+st[v][k].second;
				ans=min(res,ans);	
			}
		}
		cout<<ans+sud[u]+sud[v]<<"\n";
	}
	return 0;
}
