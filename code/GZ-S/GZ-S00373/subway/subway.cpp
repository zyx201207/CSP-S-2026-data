//GZ-S00373 贵阳市华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,qu;
vector<pair<int,int> >v[500001];
vector<pair<int,long long> >d[500001];
long long dis[5000001],w[500001];
int b[500001],ac[500001];
void dijkstra(int st) {
	memset(dis,127,sizeof dis);
	queue<int>q;
	dis[st]=0;
	b[st]=1;
	q.push(st);
	while(q.size()) {
		int qq=q.front();
		q.pop();
		b[qq]--;
		if(b[qq])continue;
		for(int i=0; i<d[qq].size(); i++) {
			if(dis[d[qq][i].first]>dis[qq]+d[qq][i].second) {
				b[d[qq][i].first]++;
				dis[d[qq][i].first]=dis[qq]+d[qq][i].second;
				q.push(d[qq][i].first);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qu;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int cnt=m;
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		int last=-2e9;
		for(int i=1; i<=k; i++) {
			int a,t;
			cin>>a>>t;

			if(v[a].size()==0) {
				v[a].push_back({a,t});
				ac[a]=t;
				if(last!=-2e9) {
					d[a].push_back({last,0});
					d[last].push_back({a,0});
				}
				last=a;
			} else {
				v[a].push_back({++cnt,t});
				ac[cnt]=t;
				if(last!=-2e9) {
					d[cnt].push_back({last,0});
					d[last].push_back({cnt,0});
				}
				last=cnt;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=0; j<v[i].size(); j++) {
			for(int k=j+1; k<v[i].size(); k++) {
				d[v[i][j].first].push_back({v[i][k].first,v[i][j].second+v[i][k].second}) ;
				d[v[i][k].first].push_back({v[i][j].first,v[i][j].second+v[i][k].second}) ;
			}
		}
	}
	while(qu--) {
		int x,y;
		cin>>x>>y;
		long long ans=4e18;
		for(int i=0; i<v[x].size(); i++) {
			dijkstra(v[x][i].first);
			for(int j=0; j<v[y].size(); j++) {
				ans=min(ans,w[x]+w[y]+dis[v[y][j].first]+ac[v[y][j].first]+ac[v[x][i].first]);
			}
		}
		cout<<ans<<endl;
	}
}

