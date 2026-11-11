#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define P pair<int,long long>

const int M=5e5+3;

int c,n,m,d,q;//n为路线数，m为站口数,d为每个站被最多被d条路线经过 
ll w[M];//w[i]:从i个地铁站的地铁口走到站厅需要的时间 
int K[505];// K[i]:表示第 i 条线路经过的地铁站数 
vector<P>l[505];//l[i]:第i条路线经过的 <站台l[i].fi,时间l[i].se>

ll fl[1005][1005];

void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			int a;
			ll t;
			cin>>a>>t;
			l[i].push_back({a,t});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)fl[i][j]=1e17;
	}
	
	for(int i=1;i<=n;i++){
		for(int x=0;x<l[i].size();x++){
			for(int y=x+1;y<l[i].size();y++){
				int u=l[i][x].fi,v=l[i][y].fi;
				ll t=l[i][x].se+l[i][y].se;
				fl[u][v]=fl[v][u]=t;
			}
		}
	}
}

void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
				//cout<<i<<" "<<j<<" "<<fl[i][j]<<'\n';
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<fl[x][y]+w[x]+w[y]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	init();
		
	floyd();
	return 0;
} 
