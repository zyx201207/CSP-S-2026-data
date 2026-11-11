#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=510;
int dian,n,m,d,q,w[N],head[N+M],tot,a[M][M];
struct node {
	int ed,val,nxt;
} edge[N+M];
void add(int u,int v,int w) {
	edge[++tot]={v,w,head[u]};
	head[u]=tot;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>dian>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++) {
		int k;cin>>k;
		for(int j=1;j<=k;j++) {
			int x,y;cin>>x>>y;
			add(x,n+i,y);
		}
	}
	memset(a,0x2f,sizeof(a));
	for(int i=1;i<=m;i++) a[i][i]=0;
	for(int i=1;i<=n;i++) {
		for(int x=head[i];x;x=edge[x].nxt) {
			for(int y=edge[x].nxt;y;y=edge[y].nxt) {
				int t1=edge[x].ed-n,t2=edge[y].ed-n;
				if(t1>t2) swap(t1,t2);
				a[t1][t2]=min(a[t1][t2],edge[x].val+edge[y].val);
			}
		}
	}
	for(int k=1;k<=m;k++) {
		for(int i=1;i<k;i++) {
			for(int j=k+1;j<=m;j++) {
				a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
			}
		}
	}
	while(q--) {
		int x,y,ans=1e18;cin>>x>>y;
		for(int p1=head[x];p1;p1=edge[p1].nxt) {
			for(int p2=head[y];p2;p2=edge[p2].nxt) {
				int t1=edge[p1].ed-n,t2=edge[p2].ed-n;
				if(t1>t2) swap(t1,t2);
				ans=min(ans,a[t1][t2]+edge[p1].val+edge[p2].val);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
