#include<bits/stdc++.h>
using namespace std;
const int M=505;
const int N=5e5+5;
struct node {
	int v,w,sta;
	node(int i=0,int j=0,int k=0):v(i),w(j),sta(k){}
	bool operator<(node a) const {return w>a.w;}
};
int c,n,m,d,q;
int w[N],k[M];
int v[M][10000],t[M][M];
int sta[N],dis[N];
vector<node> g[M];
priority_queue<node> que; 
void dij(int st) {	
	while(!que.empty()) que.pop();
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	que.push(node(st,0));
	while(!que.empty()) {
		int x=que.top().v,tim=que.top().w;
		que.pop();
		for(int i=0;i<g[x].size();i++) {
			if(tim+g[x][i].w<dis[g[x][i].v]) {
				dis[g[x][i].v]=tim+g[x][i].w;
				que.push(node(g[x][i].v,dis[g[x][i].v]));
			}	
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>v[i][j]>>t[i][v[i][j]];
			sta[v[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++) {
		if(sta[i]>=2) {
			for(int j=1;j<=n;j++) {
				int fl=0;
				for(int p=1;p<=k[j];p++) {
					if(v[j][p]==i) {
						fl=1;
						break;
					}
				}
				if(fl==0) continue;
				for(int p=1;p<=k[j];p++) {
					if(v[j][p]==i) continue;
					g[i].push_back(node(v[j][p],t[j][i]+t[j][v[j][p]],j));
					g[v[j][p]].push_back(node(i,t[j][v[j][p]]+t[j][i],0));
				}
			}
		}
	}
	for(int k=1,st,en;k<=q;k++) {
		cin>>st>>en;
		dij(st);
		cout<<dis[en]+w[st]+w[en]<<"\n"; 
	}
	return 0;
}
