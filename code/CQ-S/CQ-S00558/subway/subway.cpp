#include<bits/stdc++.h>
#define int  long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>>trans[500005];
int a[500005],t[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j],trans[a[j]].push_back({i,t[j]});
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int x=1;x<=m;x++){
		int len=trans[x].size();
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(i==j)continue;
				int u=trans[x][i].first,v=trans[x][j].first,w=trans[x][i].second+trans[x][j].second;
				dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int mn=1e18;
		for(auto u:trans[x]){
			for(auto v:trans[y])mn=min(mn,w[x]+w[y]+u.second+v.second+dis[u.first][v.first]);
		}
		cout<<mn<<"\n";
	}
}
/*
Milky Dragon.
100
*/
