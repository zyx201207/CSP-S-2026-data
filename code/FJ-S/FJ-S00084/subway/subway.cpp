#include<bits/stdc++.h>
using namespace std;
const int DOUREN=1e3;
int w[DOUREN],k[DOUREN];
struct node{
	int t1,t2;
}p[100010];
int a[DOUREN][DOUREN],t[DOUREN][DOUREN];
int fst[DOUREN],to[DOUREN],nxt[DOUREN],cnt;
void add(int a,int b) {
	to[++cnt]=b;
	nxt[cnt]=fst[a];
	fst[a]=cnt;
}
priority_queue<pair<int,int> > q;
bool vis[DOUREN];
int dis[DOUREN];
bool cg[DOUREN];
bool line[DOUREN][DOUREN];
//void dijkstra(int s) {
//	for(int i=1;i<DOUREN;i++) {
//		dis[i]=1e9;
//	}
//	dis[s]=0;
//	q.push({0,s});
//	while(q.empty()) {
//		int x=q.top().second;
//		q.pop();
//		if(vis[x]) {
//			continue;
//		}
//		for(int i=fst[x];i;i=nxt[i]) {
//			int v=to[i];
//			if(dis[v]>dis[x]+w[i]) {
//				
//			}
//		}
//	}
//}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
		p[i].t1=w[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			line[i][a[i][j]]=1;
//			p[a[j]].t2=t;
//			if(j==1) continue;
//			add(a[j],a[j-1]);
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		int s,tt;
		for(int i=1;i<=n;i++) {
			if(line[i][x]) {
				s=i;
			}
			if(line[i][y]) {
				tt=i;
			}
		}
		int ans=w[s]+w[y];
		if(s>tt) swap(s,tt);
		for(int i=s;i<=tt;i++) {
			for(int j=1;j<=k[i];j++) {
				ans+=t[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

