#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

const int N=510;
const int M=500010;
int c, n, m, d, q;
int last[M], elen=0;

struct edge{
	int x, y, t, pre;
}e[M*25];

void init(int x, int y, int t){
	e[++elen]=edge{x, y, t, last[x]};
	last[x]=elen;
}

int w[M];
ll dis[N][N];

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(last, 0, sizeof(last));
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		while(k--){
			int x, t;
			cin >> x >> t;
			init(x, i, t);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1; i<=m; i++){
		for(int k=last[i]; k; k=e[k].pre){
			int x=e[k].y, t=e[k].t;
			for(int kk=last[i]; kk; kk=e[kk].pre){
				int y=e[kk].y, tt=e[kk].t;
				if(x==y) dis[x][y]=0;
				else dis[x][y]=min(dis[x][y], (ll)t+tt);
			}
		}
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ll ans=1e18;
		for(int k=last[x]; k; k=e[k].pre){
			int xx=e[k].y, t=e[k].t;
			for(int kk=last[y]; kk; kk=e[kk].pre){
				int yy=e[kk].y, tt=e[kk].t;
				ans=min(ans, (ll)(w[x]+w[y]+dis[xx][yy]+t+tt));
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
