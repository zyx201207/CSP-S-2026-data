#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=500010;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>>v[N];
int dis[5010][5010];
void dj(int u){
	priority_queue<PII,vector<PII>,greater<PII>>p;
	p.push({0,u});
	dis[u][u]=0;
	while(p.size()){
		PII t=p.top();p.pop();
		int uu=t.second,ww=t.first;
		for(auto i:v[uu]){
			int U=i.first,W=i.second;
			if(dis[u][U]>dis[u][uu]+W){
				dis[u][U]=dis[u][uu]+W;
				p.push({dis[u][U],U});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	int cnt=m+1;
	for(int i=1; i<=m; i++) {
		int w;
		cin>>w;
		v[cnt].push_back({i,w});
		v[i].push_back({cnt++,w});

	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			PII aa=v[a].front();
			v[cnt].push_back({aa.first,t});
			v[aa.first].push_back({cnt,t});
		}
		cnt++;
	}
	for(int i=1;i<=m;i++){
		dj(i);
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 2 6 3 1 7 2
3 1 4 2 5 5 100
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
