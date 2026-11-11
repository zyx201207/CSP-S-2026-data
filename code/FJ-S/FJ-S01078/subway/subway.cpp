#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,ll> PII;

ll read() {
	ll n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	if(f==1) return n;
	return -n;
}

void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//========================================//

const int M=5e5+7,N=507;
const ll INF=1e18;

int n,m,q;
ll w[M];
vector<PII> stat[M];

//========================================//

ll f[N][N];

void floyd() {
	for(int k=1;k<=n;k++) 
		for(int i=1;i<=n;i++) 
			for(int j=i+1;j<=n;j++) {
				if(f[i][k]==INF || f[k][j]==INF) continue;
				f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
}

//========================================//

void input() {
	read(); n=read(); m=read(); read(); q=read();
	for(int i=1;i<=m;i++) 
		w[i]=read();
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=1;j<=k;j++) {
			int c=read(); ll t=read();
			stat[c].push_back((PII){i,t});
		}
	}
}

void work() {
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) 
			f[i][j]=INF;
	for(int i=1;i<=n;i++) 
		f[i][i]=0;
	for(int i=1;i<=m;i++) {
		int sz=stat[i].size();
		for(int j=0;j<sz;j++) {
			for(int k=j+1;k<sz;k++) {
				int x=stat[i][j].x,y=stat[i][k].x;
				f[x][y]=f[y][x]=min(f[x][y],stat[i][j].y+stat[i][k].y);
			}
		}
	}
	floyd();
	while(q--) {
		int x=read(); int y=read();
		int lx=stat[x].size(); int ly=stat[y].size();
		ll ans=INF;
		for(int i=0;i<lx;i++) 
			for(int j=0;j<ly;j++) 
				ans=min(ans,
					stat[x][i].y+stat[y][j].y+f[stat[x][i].x][stat[y][j].x]);
		write(ans+w[x]+w[y]),puts("");
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	work();
	return 0;
}
