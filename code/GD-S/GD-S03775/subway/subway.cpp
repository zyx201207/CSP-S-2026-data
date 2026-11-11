#include<bits/stdc++.h>
using namespace std;
#define FILE "subway"
int c,n,m,d,q;
int fa[600001];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
vector<pair<int,int>> pass[500001];
long long dis[501][501],w[500001];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			pass[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
//	cerr << "ed.\n";
	for(int i=1;i<=m;i++){
		for(int j=0,siz=pass[i].size();j<siz;j++){
			for(int k=j+1;k<siz;k++){
				int u=pass[i][j].first,v=pass[i][k].first;
				long long w=pass[i][j].second+pass[i][k].second;
				if(u>v)	swap(u,v);
				dis[u][v]=min(dis[u][v],w);
			
			}
		}
	}
//	cerr << "ed.\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],(i<k?dis[i][k]:dis[k][i])+(j<k?dis[j][k]:dis[k][j]));
			}
		}
	}
//	cerr << "ed.\n";
	while(q--){
		int x,y;
		cin >> x >> y;
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(auto &[a1,t1]:pass[x]){
			for(auto &[a2,t2]:pass[y]){
				ans=min(ans,w[x]+w[y]+t1+t2+(a1<a2?dis[a1][a2]:dis[a2][a1]));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
本关考验你floyd功夫

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8
*/ 
