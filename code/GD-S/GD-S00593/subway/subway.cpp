#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
int c,n,m,d,q;
int w[500005];
vector<pii>line[505];

vector<pii>station[505];
int k[505];
int dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			line[i].push_back(mp(a,t));
			station[a].push_back(mp(i,t));
		}
	}
	for(int i=1;i<m;i++){
		dis[1][1]=0;
		for(int j=0;j<station[i].size();j++){
			for(int k=j+1;k<station[i].size();k++){
				int lj=station[i][j].first;
				int lk=station[i][k].first;
				dis[lj][lk]=min(dis[lj][lk],station[i][i].second+station[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(n--){
		int x,y,lx,ly,ts,ty;
		cin>>x>>y;
		cout<<dis[x][y]<<endl;
	}
	return 0;
} 
