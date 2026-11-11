#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<unsigned,unsigned>> t[512345];//对于每一个点的线路之和 : 隶属的线路编号+时间
unsigned n,m,x,y,q,z; 
unsigned Walk[512345];
unsigned long long dis[520][520];
void floyd() {	
	for(int k = 1;k<=n;++k)
	for(int i = 1;i<=n;++i){unsigned long long t = dis[k][i];
	if(~t)for(int j = 1;j<=n;++j)if(~dis[k][j])if(dis[i][j] > (t+dis[k][j]))dis[i][j]=t+dis[k][j];
	}
}
int main() {
	memset(dis,0xff,sizeof dis);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>n>>m;cin>>x;cin>>q;
	for(int i = 1;i<=n;++i)dis[i][i] = 0;
	for(int i = 1;i<=m;++i) cin>>Walk[i];
	for(int i = 1;i<=n;++i) {
		cin>>z;
		for(int j = 0;j<z;++j){
			cin>>x>>y;
			t[x].emplace_back(i,y);
		}
	}
	for(int i = 1;i<=m;++i) {
		for(int j = 0;j<t[i].size();++j)
			for(int k = 0;k<j;++k){
				dis[t[i][j].first][t[i][k].first] = dis[t[i][k].first][t[i][j].first] =
					min<unsigned long long>(dis[t[i][j].first][t[i][k].first] , t[i][j].second + t[i][k].second );
			}
	}
	floyd();
//	cout<<"FLOYD!\n";
	while(q--) {
		unsigned long long ans = -1;
		cin>>x>>y;
		for(int i = 0; i< t[x].size();++i)for(int j = 0;j < t[y].size();++j) ans = 
			min(ans,dis[t[x][i].first][t[y][j].first] + t[x][i].second+t[y][j].second);
		cout<<(ans + Walk[x] + Walk[y])<<'\n';
	}
	return 0;
}

