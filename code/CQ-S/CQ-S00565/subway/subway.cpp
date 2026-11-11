#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,n,m,d,q,x,y,k[505];
ll w[500005],Mn[505][505],ans; pair<int,int> Now[505][505];
vector<int> a[505]; vector<ll> t[505];
vector<pair<int,ll> > V[500005]; map<int,ll> Mp[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> C >> n >> m >> d >> q,memset(Mn,0x3f3f,sizeof(Mn));
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i],a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++) cin >> a[i][j] >> t[i][j],V[a[i][j]].push_back({i,t[i][j]}),Mp[i][a[i][j]]=t[i][j];
	} for(int i=1;i<=m;i++) for(int j=0;j<V[i].size();j++) 
		for(int k=j+1;k<V[i].size();k++) if(Mn[V[i][j].first][V[i][k].first]>V[i][j].second+V[i][k].second)
			Mn[V[i][j].first][V[i][k].first]=Mn[V[i][k].first][V[i][j].first]=V[i][j].second+V[i][k].second,
			Now[V[i][j].first][V[i][k].first]=Now[V[i][k].first][V[i][j].first]={i,i};
	for(int i=1;i<=n;i++) Mn[i][i]=0;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(Mn[i][j]>Mn[i][k]+Mn[k][j])
			Mn[i][j]=Mn[i][k]+Mn[k][j],Now[i][j]={Now[i][k].first,Now[k][j].second};
	while(q--){
		cin >> x >> y,ans=1e18;
		for(int i=0;i<V[x].size();i++) for(int j=0;j<V[y].size();j++)
			ans=min(ans,Mn[V[x][i].first][V[y][j].first]+(Now[V[x][i].first][V[y][j].first].first!=x)*
				Mp[V[x][i].first][x]+(Now[V[x][i].first][V[y][j].first].second!=y)*Mp[V[y][j].first][y]+w[x]+w[y]);
		cout << ans << '\n'; 
	} return 0;
}
