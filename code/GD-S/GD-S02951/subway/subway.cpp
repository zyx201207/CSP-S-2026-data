#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> >station[500010];//line、time
struct RP {
	int x,time,li;//在哪个地铁站、所用时间、在哪一条地铁线上
};
struct Node {
	vector<pair<int,int> >a;//地铁站、去站厅time
} line[510];
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[500010];//从每个地铁站的地铁口走到站厅需要的时间
int x,y;
bool vis[500010];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)scanf("%d",&w[i]);
	for(int i=1; i<=n; i++) {
		int k;
		scanf("%d",&k);
		for(int j=1; j<=k; j++) {
			int a,t;
			scanf("%d%d",&a,&t);
			station[a].push_back(make_pair(i,t));
			line[i].a.push_back(make_pair(a,t));
		}
	}
	while(q--) {
		scanf("%d%d",&x,&y);
		int ans=0;
		queue<RP>q;
		q.push({x,w[x]+w[y],0});
		while(!q.empty()) {
			int s=q.front().x,t=q.front().time,l=q.front().li;
			q.pop();
			for(int i=0; i<(int)station[x].size(); i++) {
				for(int j=0; j<(int)line[station[x][i].first].a.size(); j++) {
//					int s_=line[station[x][i].first][j].first,ti=t+station[x][i].second;
//					if(station[x][i].first==l)ti=t;
//					else if(station[x][i].first!=0)ti+=line[l]
					}
			}
		}
	}
	return 0;
}

