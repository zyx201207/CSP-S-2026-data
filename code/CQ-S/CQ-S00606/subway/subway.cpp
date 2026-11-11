#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+9999;
const int N=502;
const ll inf=1e18;

int TID,n,m,d,Q;

ll w[M];

ll dis[N][N];

vector<pair<int,ll> > v[M];

void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>TID>>n>>m>>d>>Q;
//	cerr<<TID<<" "<<n<<" "<<m<<" "<<d<<" "<<Q<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j){
				dis[i][j]=0;
			}else{
				dis[i][j]=inf;
			}
		}
	}
	
	for(int i=1;i<=m;++i){
		cin>>w[i];
//		cerr<<w[i]<<" ";
	}
//	cerr<<endl;
	
	for(int i=1,k;i<=n;++i){
		cin>>k;
//		cerr<<i<<": ";
		for(int j=1,a,b;j<=k;++j){
			cin>>a>>b;
			v[a].emplace_back(i,b);
//			cerr<<a<<" "<<b<<"|";
		}
//		cerr<<endl;
	}
	
	for(int i=1;i<=m;++i){
//		if(v[i].size()==0){
//			cerr<<i<<" ";
//		}
		for(int j=0;j<v[i].size();++j){
			for(int k=0;k<v[i].size();++k){
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cerr<<dis[i][j]<<" ";
//		}
//		cerr<<endl;
//	}
	floyd();
	
	for(int i=1,x,y;i<=Q;++i){
		cin>>x>>y;
		ll ds=inf;
		for(int j=0;j<v[x].size();++j){
			for(int k=0;k<v[y].size();++k){
//				cerr<<dis[v[x][j].first][v[y][k].first]<<" ";
				ds=min(ds,v[x][j].second+v[y][k].second+dis[v[x][j].first][v[y][k].first]);
			}
		}
//		cerr<<endl;
		cout<<ds+w[x]+w[y]<<"\n";
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
