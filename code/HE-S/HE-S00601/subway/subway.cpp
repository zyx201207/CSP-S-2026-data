#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[50000010],dis[1000010];
vector<pair<int,int> >mp[1000010],xl[510];
vector<int>mk[500010];
void dij(int s){
	memset(dis,0x7f,sizeof(dis));
	priority_queue<pair<int,int> >ma;
	ma.push({0,s});
	dis[s]=0;
	while(ma.size()){
		auto ak=ma.top();
		ma.pop();
		for(auto c:mp[ak.second]){
			if(dis[c.first]>dis[ak.second]+c.second){
				dis[c.first]=dis[ak.second]+c.second;
				ma.push({dis[c.first],c.first});
			}
		}
	}
}
signed main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
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
			int ai,ki;
			cin>>ai>>ki;
			xl[i].push_back({ai,ki});
			if(j>=2){
				mp[xl[i][j-1].first+i*m-m].push_back({xl[i][j-2].first+i*m-m,0});
				mp[xl[i][j-2].first+i*m-m].push_back({xl[i][j-1].first+i*m-m,0});
			}
			mp[xl[i][j-1].first+i*m-m].push_back({xl[i][j-1].first+m*n,xl[i][j-1].second});
			mp[xl[i][j-1].first+m*n].push_back({xl[i][j-1].first+i*m-m,xl[i][j-1].second});
		}
	}
	for(int i=1;i<=q;i++){
		if(i%10000==0)
		cerr<<i<<" ";
		int x,y;
		cin>>x>>y;
		dij(x+m*n);
		cout<<dis[y+m*n]+w[x]+w[y]<<'\n';
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
