#include <bits/stdc++.h>
#define OUT(x) ' '<<(#x)<<'='<<(x)<<' '
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=505,MAXM=500005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int CASE,N,M,D,Q,into[MAXM];
vector<pii> pass[MAXM];
ll dis[MAXN][MAXN];
//struct Line{
//	int k;
//	vector<int> a,t;
//}l[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>CASE>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>into[i];
	}
	for(int i=1;i<=N;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			pass[a].push_back((pii){i,t});
//			l[i].a.push_back(a),l[i].t.push_back(t);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=M;i++){
		int siz=pass[i].size();
		for(int u=0;u<siz;u++){
			for(int v=u+1;v<siz;v++){
				int x=pass[i][u].first,y=pass[i][v].first;
				dis[x][y]=dis[y][x]=min(dis[x][y],1ll*pass[i][u].second+pass[i][v].second);
				//cout<<i<<' '<<x<<' '<<y<<' '<<pass[i][u].second+pass[i][v].second<<'\n';
			}
		}
	}
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	while(Q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<(int)pass[x].size();i++){
			for(int j=0;j<(int)pass[y].size();j++){
				//cout<<OUT(pass[x][i].first)<<OUT(pass[y][j].first)<<OUT(dis[pass[x][i].first][pass[y][j].first])<<'\n';
				ans=min(ans,dis[pass[x][i].first][pass[y][j].first]+pass[x][i].second+pass[y][j].second);
			}
		}
		cout<<1ll*into[x]+into[y]+ans<<'\n';
	}
	return 0;
} 
