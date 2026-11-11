#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define x first
#define y second
#define endl '\n'
using namespace std;
const int N=510,M=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
// 数组不要开小 
/*
当前在线路 i，去线路 j 的最小代价 n^3 
枚举两个站的线路 d^2
直接查表，就对了！ 
*/
int cid,n,m,d,q;
int g[N][N],w[M];
vector<PII> vec[M];
vector<PII> tt[M];
int v[N];
void solve() {
	cin>>cid>>n>>m>>d>>q;
	upp(i,1,m) cin>>w[i];
	upp(i,1,n) {
		int len;cin>>len;
		upp(j,1,len) {
			int x,y;cin>>x>>y;
			vec[x].pb({i,y});
			tt[i].pb({x,y});
		}
	}
	upp(i,1,n) {
		memset(v,0x3f,sizeof v);
		for(auto x:tt[i]) {
			for(auto y:vec[x.x]) {
				if(y.x==i) continue;
				v[y.x]=min(v[y.x],y.y+x.y);
			}
		}
		upp(j,1,n) g[i][j]=v[j];
		g[i][i]=0;
	}
	upp(k,1,n) {
		upp(i,1,n) {
			upp(j,1,n) {
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	// 加油
	upp(i,1,q) {
		int x,y;cin>>x>>y;
		int ans=INF;
		for(auto xx:vec[x]) {
			for(auto yy:vec[y]) {
				ans=min(ans,w[x]+w[y]+xx.y+yy.y+g[xx.x][yy.x]);
			}
		}
		cout<<ans<<endl;
	} 
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tts=1;
	while(tts--) solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

