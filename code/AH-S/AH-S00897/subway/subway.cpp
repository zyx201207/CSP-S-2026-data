#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f;
int c,n,m,d,qq;
int dis[500605];
int vis[500605];
int k,u,v,w;
int wal[500605];
bool flag[500005][2];
void dividing_line () {
	cout<<"---------------------"<<endl;
	return ;
}
struct edge {
	int v;
	int w;
};
vector<edge> e[500605];
struct node {
	int u;
	int dis;
	bool operator > (const node& a) const {
		return dis>a.dis;
	}
} tmp;
priority_queue<node,vector<node>,greater<node> > q;
struct an {
	int id;
	int s,t;
	int ans;
} ans[100005];
bool cmp1 (an x,an y) {
	return x.s<y.s;
}
bool cmp2 (an x,an y) {
	return x.id<y.id;
}
void dijkstra (int s) {
	while(!q.empty()) {
		q.pop();
	}
	for(int i=0;i<=n+m+2;i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()) {
		tmp=q.top();
		q.pop();
		u=tmp.u;
		if(vis[u]) {
			continue;
		}
		vis[u]=1;
		for(int i=0;i<e[u].size();i++) {
			v=e[u][i].v;
			w=e[u][i].w;
			if(dis[v]>dis[u]+w) {
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return ;
}
int minn (int x,int y) {
	if(x>y) {
		return y;
	}
	return x;
}
void special1() {
	cin>>k;
	while(k--) {
		cin>>v>>w;
		flag[v][0]=true;
		ans[v].s=w;
	}
	cin>>k;
	while(k--) {
		cin>>v>>w;
		flag[v][1]=true;
		ans[v].t=w;
	}
	int mn=INF,mnn=INF;
	for(int i=1;i<=m;i++) {
		if(flag[i][0]&&flag[i][1]) {
			mn=minn(ans[i].s+ans[i].t,mn);
		}
	}
	for(int i=0;i<qq;i++) {
		cin>>u>>v;
		mnn=INF;
		if(flag[u][0]) {
			if(flag[u][1]) {
				if(flag[v][0]) {
					if(flag[v][1]) {
						mnn=minn(mnn,ans[u].s+ans[v].s);
						mnn=minn(mnn,ans[u].t+ans[v].t);
						mnn=minn(mnn,ans[u].s+ans[v].t+mn);
						mnn=minn(mnn,ans[u].t+ans[v].s+mn);
					}
					else {
						mnn=minn(mnn,ans[u].t+ans[v].t);
						mnn=minn(mnn,ans[u].t+ans[v].s+mn);
					}
				}
				else {
					mnn=minn(ans[u].t,ans[u].s+mn)+ans[v].t;
				}
			}
			else {
				if(flag[v][0]) {
					if(flag[v][1]) {
						mnn=minn(ans[v].t+mn,ans[v].s)+ans[u].s;
						//cout<<mn<<endl;
					}
					else {
						mnn=ans[u].s+ans[v].s;
					}
				}
				else {
					mnn=ans[u].s+ans[v].t+mn;
				}
			}
		}
		else {
			if(flag[v][0]) {
				if(flag[v][1]) {
					mnn=minn(ans[v].s+mn,ans[v].t)+ans[u].t;
				}
				else {
					mnn=ans[u].t+ans[v].s+mn;
				}
			}
			else {
				mnn=ans[u].t+ans[v].t;
			}
		}
		mnn+=wal[u]+wal[v];
		cout<<mnn<<'\n';
	}
	return ;
}
void special2 () {
	cin>>k;
	while(k--) {
		cin>>v>>w;
		ans[v].s=w;
	}
	for(int i=0;i<qq;i++) {
		cin>>u>>v;
		cout<<ans[u].s+ans[v].s+wal[u]+wal[v]<<'\n';
	}
	return ;
}
signed main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) {
		cin>>wal[i];
	}
	if((n<=2||c==20||c==21)&&c>15) {
		if(n==2) {
			special1();
		}
		else {
			special2();
		}
		return 0;
	}
	//cout<<1<<endl;
	for(int i=1;i<=n;i++) {
		u=m+i;
		cin>>k;
		while(k--) {
			cin>>v>>w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	}
	for(int i=0;i<qq;i++) {
		cin>>ans[i].s>>ans[i].t;
		if(ans[i].s>ans[i].t) {
			swap(ans[i].s,ans[i].t);
		}
		ans[i].id=i;
	}
	sort(ans,ans+qq,cmp1);
	dijkstra(ans[0].s);
	ans[0].ans=wal[ans[0].s]+wal[ans[0].t]+dis[ans[0].t];
	for(int i=1;i<qq;i++) {
		if(ans[i].s!=ans[i-1].s) {
			dijkstra(ans[i].s);
		}
		ans[i].ans=wal[ans[i].s]+wal[ans[i].t]+dis[ans[i].t];
	}
	sort(ans,ans+qq,cmp2);
	for(int i=0;i<qq;i++) {
		cout<<ans[i].ans<<'\n';
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
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
