#include<bits/stdc++.h>
#define MAXN 500005
#define inf 0x3f3f3f3f3f3f3f3f
#define dmax 22
using namespace std;
struct edge {
	long long to,w;
};
vector<edge> g[MAXN*(dmax+2)];
vector<edge> ga[MAXN];
struct node {
	long long u,w;
	bool operator<(const node &o) const {
		return w>o.w;
	}
};
long long gsta(long long x) {
	return x*dmax;
}
long long gtrain(long long sta,long long line) {
	return sta*dmax+line;
}
long long w[MAXN];
long long c,n,m,d,q;
long long vis[MAXN*dmax],dis[MAXN*dmax];
//long long res[5005][5005];
void init() {
	for(long long i=0;i<=(m+3)*dmax;i++) vis[i]=0;
	for(long long i=0;i<=(m+3)*dmax+3;i++) dis[i]=inf;
	//for(long long i=0;i<=n+3;i++)
}
void init2() {
	for(long long i=0;i<=(m+3);i++) vis[i]=0;
	for(long long i=0;i<=(m+3)+3;i++) dis[i]=inf;
	//for(long long i=0;i<=n+3;i++)
}
long long dij(long long s,long long t) {
	init();
	priority_queue<node> q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()) {
		node cur=q.top();
		q.pop();
		long long now=cur.u;
		//cout<<now<<endl;
		if (vis[now]) continue;
		vis[now]=1;
		for(edge v:g[cur.u]) {
			long long to=v.to,val=v.w;
			//cout<<now<<" "<<to<<endl;
			if (dis[to]>dis[now]+v.w) {
				dis[to]=dis[now]+v.w;
				q.push({to,val+cur.w});
			}
		}
	}
	return dis[t];
}
long long dij2(long long s,long long t) {
	init2();
	priority_queue<node> q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()) {
		node cur=q.top();
		q.pop();
		long long now=cur.u;
		//cout<<now<<endl;
		if (vis[now]) continue;
		vis[now]=1;
		for(edge v:ga[cur.u]) {
			long long to=v.to,val=v.w;
			//cout<<now<<" "<<to<<endl;
			if (dis[to]>dis[now]+v.w) {
				dis[to]=dis[now]+v.w;
				q.push({to,val+cur.w});
			}
		}
	}
	return dis[t];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	bool checkA=1;
	for(long long i=1,k;i<=n;i++) {
		cin>>k;
		checkA&=(k<=2);
		long long lst=-1;
		long long timea=0;
		for(long long j=1,sta,time;j<=k;j++) {
			cin>>sta>>time;
			timea+=time;
			long long trcur=gtrain(sta,i),stacur=gsta(sta);
		    g[stacur].push_back({trcur,time});//站台和站厅 
		    g[trcur].push_back({stacur,time});
		    //cout<<stacur<<" "<<trcur<<" "<<sta<<endl;
		    if (lst!=-1) {
		    	g[gtrain(lst,i)].push_back({trcur,0});//站台与站台 
		    	g[trcur].push_back({gtrain(lst,i),0});
		    	if (k==2) {
		    	    ga[lst].push_back({sta,timea});
		    	    ga[sta].push_back({timea,sta});
				}
		    	//cout<<trcur<<" "<<gtrain(lst,i)<<endl;
			}
			lst=sta;
		}
	}
	/*
	for(long long i=1;i<=m*(dmax+3);i++) {
		dij(i);
		for(long long j=1;j<=m*(dmax+3);j++) {
			//cout<<i<<" "<<j<<endl;
			res[i][j]=dis[j];
		}
	}*/
	for(long long i=1;i<=q;i++) {
		long long s,t;
		cin>>s>>t;
		if (checkA) {
			cout<<dij2(s,t)+w[s]+w[t]<<"\n";
			continue;
		}
		cout<<dij(gsta(s),gsta(t))+w[s]+w[t]<<"\n";
	}
}
/*
0 2 5 20 1
4 1 9 2 5
2 1 5 2 7 
2 2 3 3 4 
1 3
*/

