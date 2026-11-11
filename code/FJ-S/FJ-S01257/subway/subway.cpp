#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>> tim[505];
int dist[25][25];
bool graph[25][25];
int c,n,m,d,q;
int w[500005];
void init(int d){
	for(int i=1;i<=d;i++){
		for(int j=1;j<=d;j++){
			dist[i][j]=INF;
			graph[i][j]=false;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	init(d);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			tim[i].push_back({v,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<tim[i].size();j++){
			for(int h=j+1;h<tim[i].size();h++){
				dist[tim[i][j].first][tim[i][h].first]=min(dist[tim[i][j].first][tim[i][h].first],tim[i][j].second+tim[i][h].second);
				dist[tim[i][h].first][tim[i][j].first]=dist[tim[i][j].first][tim[i][h].first];
				graph[tim[i][j].first][tim[i][h].first]=graph[tim[i][h].first][tim[i][j].first]=true;
			}
		}
	}
	for(int i=1;i<=d;i++){
		for(int j=i+1;j<=d;j++){
			for(int k=1;k<=d;k++){
				if(i!=j&&j!=k&&i!=k&&!graph[i][j]&&graph[i][k]&&graph[k][j]){
					dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
					dist[j][i]=dist[i][j];
				}
			}
			graph[i][j]=graph[j][i]=true;
		}
	}
	for(int i=0;i<q;i++){
		int bg,ed;
		cin>>bg>>ed;
		printf("%lld\n",dist[bg][ed]+w[bg]+w[ed]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

