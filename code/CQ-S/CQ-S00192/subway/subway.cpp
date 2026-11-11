#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[500010];
vector<int>v1[500010];//经过i站的所有线路
vector<int>v2[500010];//经过i站的所有线路的厅->台时间
ll e[510][510]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//int T=clock();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v1[a].push_back(i);
			v2[a].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)v1[i].size();j++){
			for(int k=j+1;k<(int)v1[i].size();k++){
				int x=v1[i][j];
				int y=v1[i][k];
				e[x][y]=e[y][x]=min(e[x][y],1LL*v2[i][j]+v2[i][k]);
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
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=inf;
		for(int i=0;i<(int)v1[x].size();i++){
			for(int j=0;j<(int)v1[y].size();j++){
				int u=v1[x][i];
				int v=v1[y][j];
				res=min(res,e[u][v]+v2[x][i]+v2[y][j]+w[x]+w[y]);
			}
		}
		cout<<res<<"\n";
	}
	//cerr<<"time:"<<clock()-T<<endl;
	return 0;
}
