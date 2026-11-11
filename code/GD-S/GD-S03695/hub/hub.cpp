#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T;
int n,k,dis[N],rk[N],ans;
vector<int>ld[N];
int mq[N],lq,rq;
struct node {
	int p,d;
	bool operator <(const node o)const {
		return d<o.d;
	}
}ele[N];
void bfs(int x,int y) {
	lq=1,rq=0;
	for(int i=1;i<=n;i++) dis[i]=n+1;
	dis[x]=dis[y]=0;
	mq[++rq]=x,mq[++rq]=y;
	while(lq<=rq) {
		int u=mq[lq++];
		for(int v:ld[u]) {
			if(dis[v]==n+1) dis[v]=dis[u]+1,mq[++rq]=v;
		}
	}
}
bool cmp(int x,int y) {
	return x>y;
}
void dfs(int u,int d) {
//	cout<<u<<" "<<d<<"\n";
	dis[u]=d;
	for(int v:ld[u]) {
		if(dis[v]==n+1) dfs(v,d+1);
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		ans=n+1;
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			ld[u].push_back(v);
			ld[v].push_back(u);
		}
		if(13<=c&&c<=14) {
			for(int i=1;i<=n;i++) dis[i]=n+1;
			dfs(1,0);
			int rt=0;
			for(int i=1;i<=n;i++) if(dis[i]>dis[rt]) rt=i;
			for(int i=1;i<=n;i++) dis[i]=n+1;
			dfs(rt,0);
			for(int i=1;i<=n;i++) if(dis[i]>dis[rt]) rt=i;
			cout<<(dis[rt]-k+5)/4<<"\n";
			for(int i=1;i<=n;i++) ld[i].clear();
			continue;
		}
		for(int rt1=1;rt1<=n;rt1++) {
			for(int rt2=rt1+1;rt2<=n;rt2++) {
				bfs(rt1,rt2);
				for(int i=1;i<=n;i++) {
					ele[i].p=i,ele[i].d=dis[i],rk[i]=1;
				}
				sort(ele+1,ele+1+n);
				for(int i=n;i>=1;i--) {
					int u=ele[i].p;
					for(int v:ld[u]) if(dis[v]<dis[u]) rk[v]=rk[u]+1;
				}
				sort(rk+1,rk+1+n,cmp);
//				if(ans==1) cout<<rt1<<" "<<rt2<<"\n";
				ans=min(ans,rk[k+1]);
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) ld[i].clear();
	}
}
