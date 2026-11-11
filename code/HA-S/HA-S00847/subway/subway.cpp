#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500001],k[500001];
vector<int>a[501];
vector<int>t[501];
int inf=1e16;
struct sta{
	int train,id;
};
vector<sta>station[500001];
int dis[501][501];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			if(j==1){
				a[i].push_back(0);
				t[i].push_back(0);
			}
			int _,__;
			cin>>_>>__;
			a[i].push_back(_);
			t[i].push_back(__);
			station[a[i][j]].push_back({i,j});
		}for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}dis[i][i]=0;
	}for(int i=1;i<=m;i++){
		for(int j=0;j<station[i].size();j++){
			for(int k=0;k<station[i].size();k++){
				dis[station[i][j].train][station[i][k].train]
				=dis[station[i][k].train][station[i][j].train]
				=dis[station[i][k].train][station[i][j].train]=
				min(dis[station[i][k].train][station[i][j].train],
				t[station[i][j].train][station[i][j].id]+t[station[i][k].train][station[i][k].id]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=inf;
		cin>>x>>y;
		for(int j=0;j<station[x].size();j++){
			for(int k=0;k<station[y].size();k++){
				ans=min(ans,w[x]+w[y]+t[station[x][j].train][station[x][j].id]+t[station[y][k].train][station[y][k].id]+dis[station[x][j].train][station[y][k].train]);
			}
		}cout<<ans<<"\n";
	}	
}
