/*
	subway
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=505;
const ll INF=1e18;
struct node{
	int id;
	ll t;
};

vector<node>stat[N];

int c,n,m,d,q;
ll w[N];
ll f[M][M];

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
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			stat[a].push_back({i,t});
		}
	}
	
	//开始建边
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				f[i][j]=0;
				continue;
			}
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		int len=stat[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int u=stat[i][j].id,v=stat[i][k].id;
				ll d=stat[i][j].t+stat[i][k].t;
				f[u][v]=min(f[u][v],d);
				f[v][u]=min(f[v][u],d);
			}
		}
	} 
	
	//开始floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	} 
	
//	测试
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	} 
//	cout<<"\n";
//	for(int i=1;i<=m;i++){
//		for(auto e:stat[i]){
//			cout<<e.id<<" "; 
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	
	//开始回答 
	while(q--){
		ll ans=INF;
		int x,y;
		cin>>x>>y;
		for(int i=0;i<(int)stat[x].size();i++){
			for(int j=0;j<(int)stat[y].size();j++){
				int u=stat[x][i].id,v=stat[y][j].id;
				if(f[u][v]+stat[x][i].t+stat[y][j].t<=ans){
					ans=f[u][v]+stat[x][i].t+stat[y][j].t;
				}
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	} 
	return 0;
}
