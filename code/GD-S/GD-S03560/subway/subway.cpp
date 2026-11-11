#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int M=1e5+7;
int c,n,m,d,q,k[507],ql[M],qr[M];
vector<vector<pair<int,long long>>>v(N+M,vector<pair<int,long long>>());
long long dis[505][2007];
long long w[N];
void dijistra(int fa){
	for(int i=1;i<=m+n;i++){
		dis[fa][i]=1e18;
	}
	dis[fa][fa+m]=0;
	priority_queue<pair<long long,int>>pq;
	pq.push({0,fa+m});
	while(pq.size()){
		long long y=pq.top().first;
		int x=pq.top().second;
		pq.pop();
		if(y>dis[fa][x])continue;
		for(int i=0;i<v[x].size();i++){
			int u=v[x][i].first;
			long long w=v[x][i].second;
			if(y+w<dis[fa][u]){
				dis[fa][u]=y+w;
				pq.push({dis[fa][u],u});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			v[x].push_back({m+i,y});
			v[m+i].push_back({x,y});
		}
	}
	for(int i=1;i<=n;i++){
		dijistra(i);
//		for(int j=1;j<=n+m;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>ql[i]>>qr[i];
		long long ans=1e18;
		for(int k=1;k<=n;k++){
			ans=min(ans,dis[k][ql[i]]+dis[k][qr[i]]);
		}
		cout<<ans+w[ql[i]]+w[qr[i]]<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

