#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
typedef pair<int,LL> PII;
const int N=5e5+10,M=505;
const LL inf=1e18;
int n,m,d,q,w[N];
vector<PII> vec[N];
LL dist[M][M];
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			vec[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(PII a:vec[i])
			for(PII b:vec[i]){
				int x=a.first,y=b.first;
				dist[x][y]=dist[y][x]=min(dist[x][y],a.second+b.second);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int x,y;
		LL ans=inf;
		cin>>x>>y;
		for(PII a:vec[x])
			for(PII b:vec[y])
				ans=min(ans,w[x]+w[y]+a.second+b.second+dist[a.first][b.first]);
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	solve();
	return 0;
}
