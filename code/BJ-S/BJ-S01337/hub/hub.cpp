#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=1e9;
int n,k,head[N],tot=0,d[15][15];
bool chs[N],vis[N];
struct E {int v,nxt;}e[N<<1];
inline void AddEdge(int u,int v) {e[++tot]={v,head[u]},head[u]=tot;}
inline void dfs(int u,int fu,int rt,int dis) {
	d[rt][u]=dis;
	for (int i=head[u];i;i=e[i].nxt)
		if (e[i].v!=fu) dfs(e[i].v,u,rt,dis+1);
}
inline void dfs1(int u) {
	vis[u]=1;
	for (int i=head[u];i;i=e[i].nxt)
		if (chs[e[i].v]&&!vis[e[i].v]) dfs1(e[i].v);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ID,T; cin>>ID>>T;
	while (T--) {
		cin>>n>>k; int u,v; tot=0;
		for (int i=1;i<=n;i++) head[i]=0;
		for (int i=1;i<n;i++) cin>>u>>v,AddEdge(u,v),AddEdge(v,u);
		if (ID<=3) {
			int mx=(1<<n)-1,ans=INF;
			for (int i=1;i<=n;i++) dfs(i,0,i,0);
			for (int sta=0;sta<=mx;sta++) {
				int cnt=0,cntk=0,now=0;
				for (int i=0;i<n;i++) chs[i+1]=((sta>>i)&1),cntk+=chs[i+1],vis[i+1]=0;
				if (cntk!=k) continue;
				for (int i=1;i<=n;i++)
					if (chs[i]&&!vis[i]) dfs1(i),cnt++;
				if (cnt>2) continue;
				for (int i=1;i<=n;i++) {
					int r=INF;
					for (int j=1;j<=n;j++)
						if (chs[j]) r=min(r,d[i][j]);
					now=max(now,r);
				}
				ans=min(ans,now);
			}
			cout<<ans<<"\n";
		}
		/*else if (ID<=14&&ID>=13) {
			if (k==1) {cout<<n/2<<"\n"; continue;}
			if (k&1) {
				if (k==n) {cout<<"0\n"; continue;}
				k/=2; int len=n-n/2;
				if (len&1) cout<<len/2-(k-1)/2<<"\n";
				else cout<<len/2-k/2<<"\n";
			}
			else {
				k/=2; int len=n-n/2;
				if (len&1) cout<<len/2-(k-1)/2<<"\n";
				else cout<<len/2-k/2<<"\n";
			}
		}
	/*	else {
			
		}*/
	}
	return 0;
}