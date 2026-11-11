#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int N = 510, M=5e5+10, D=25, inf=2e9+10;
const ll INF=2e17;

int c,n,m,d,q,w[M],k[N], ld[N][N];
bool tr[N];
ll di[N][N];

struct node {
	int a, t;
};

struct dij {
	int i; ll d;
};

bool operator <(dij x,dij y) {
	return x.d>y.d;
} 

vector<node> ts[N],ls[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
		ls[i].clear(); 
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			ld[i][j]=inf;
			if(i==j)ld[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++) {
		ts[i].clear();
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			int ax, tx; cin>>ax>>tx;
			ts[i].push_back({ax,tx});
			ls[ax].push_back({i,tx});
		}
	}
	for(int i=1;i<=m;i++) {
		int r=ls[i].size();
		for(int j=0;j<r;j++) {
			for(int k=0;k<r;k++) {
				ld[ls[i][j].a][ls[i][k].a]=min(ld[ls[i][j].a][ls[i][k].a], ls[i][j].t+ls[i][k].t);	
			}
		}
	}
	for(int s=1;s<=n;s++) {
		for(int i=1;i<=n;i++) {
			tr[i]=0, di[s][i]=INF;
		}
		di[s][s]=0;
		priority_queue<dij> Q;
		Q.push({s, 0});
		while(!Q.empty()) {
			dij k=Q.top(); Q.pop();
			int i=k.i; ll dx=k.d;
			if(tr[i])continue;
			tr[i]=1;
			for(int j=1;j<=n;j++) {
				if(i==j)continue;
				if(ld[i][j]==inf)continue;
				if((dx+ld[i][j])<di[s][j]) {
					di[s][j]=dx+ld[i][j];
					Q.push({j, dx+ld[i][j]});
				}
			}
		}
	}
	while(q--) {
		int x, y; cin>>x>>y;
		int rx=ls[x].size(), ry=ls[y].size();
		ll ans=INF;
		for(int p=0;p<rx;p++) {
			int s=ls[x][p].a;
			for(int g=0;g<ry;g++) {
				int t=ls[y][g].a;
				ll val=di[s][t]+ls[x][p].t+ls[y][g].t+w[x]+w[y];
				ans=min(ans,val);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

// DONE 16:12
// green
// might 92pts
// believe ccf pingceji.
