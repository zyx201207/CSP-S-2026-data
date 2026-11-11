#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define Gor(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)
using namespace std;
const int N=5e5+10,M=505,K=21,inf=2e18;
int C,n,m,D,Q,w[N],dis[M][M],len[M],e[N][K],v[N][K],sz[N];
//vector<int>a[M],t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS
	cin >> C >> n >> m >> D >> Q;
	For(i,1,m) cin >> w[i];
	For(i,1,n){
		cin >> len[i];
//		a[i].push_back(0);
//		t[i].push_back(0);
		For(j,1,len[i]){
			int x,y;
			cin >> x >> y;
//			a[i].push_back(x);
//			t[i].push_back(y);
			sz[x];
			e[x][++sz[x]]=i;
			v[x][sz[x]]=y;
		}
	}
	mem(dis,0x3f);
	For(i,1,m){
		For(j,1,sz[i]){
			int x=e[i][j],vx=v[i][j],y,vy;
			For(k,1,sz[i]){
				if (j==k) continue;
				y=e[i][k],vy=v[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],vx+vy);
			}
		}
	}
	For(i,1,n) dis[i][i]=0;
	For(k,1,n){
		For(i,1,n){
			For(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	For(i,1,Q){
		int x,y;
		cin >> x >> y;
		int ans=inf;
		For(j,1,sz[x]){
			For(k,1,sz[y]){
				ans=min(ans,w[x]+v[x][j]+dis[e[x][j]][e[y][k]]+v[y][k]+w[y]);
			}
		}
		cout << ans << '\n';
	}
}
