#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define lep(i,a,b) for(int i = a,ed##i = b;i <= ed##i; ++i)
#define rep(i,a,b) for(int i = a,ed##i = b;i >= ed##i; --i)
int rd(){
	int res = 0,f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res * f;
}
bool kkk1;
const int N = 2007,inf = 1e9;
typedef pair<int,int> pii;
int W[N],a[N][N],t[N][N],e[N][N];
int n,m,d,q;
bool kkk2;
namespace Sub1{
	const int M = 2e4 + 7;
	typedef pair<int,int> pii;
	map<pii,bool> mp;
	vector<int> ed[M];
	bool vis[M << 2];
	int val[M << 2],cnt = 0,dis[M << 2];
	void bfs(int s){
		queue<pii> que;
		que.push({0,s});
		vis[s] = 1;
		while(!que.empty()){
			pii idx = que.front();
			que.pop();
			int now = idx.first,u = idx.second;
			for(int v : ed[u]){
				if(vis[v] && v <= m) continue;
				vis[v] = 1;
				dis[v] = dis[u] + val[v];
				cerr << v << ' ' << dis[v] << ' ' << val[v] << '\n';
			}
		}
	}
	void sol(){
		lep(i,1,m) W[i] = rd();
		cnt = m;
		lep(i,1,n){
			int k = rd(); ++cnt;int ti;
			lep(i,1,k){
				int u = rd(),ti = rd();
				cerr << ti << ' ';
				ed[u].push_back(cnt);
				ed[cnt].push_back(u);
			}
			val[cnt] = ti*2;
			cerr << cnt << ' ' << val[cnt] << ' '<< ti <<  '\n';
		} 
 		lep(i,1,q){
			int u = rd(),v = rd();
			bfs(u);
			cout << dis[v] << '\n';
		}
	}
}
signed main( void ){
//	cout << (&kkk1 - &kkk2) / (1024 * 1024) << '\n';
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Case = rd();
	n = rd(),m = rd(),d = rd(),q = rd();
//	if(m >= 1e3){
//		Sub1::sol();
//		return 0;
//	}
	lep(i,1,m)lep(j,1,m) e[i][j] = inf;
	lep(i,1,m) W[i] = rd();
	lep(i,1,n){
		int k = rd();
		lep(j,1,k){
			a[i][j] = rd(),t[i][j] = rd();
		}
		lep(j,1,k){
			lep(l,j+1,k){
				int ti = t[i][j] + t[i][l];
				e[a[i][j]][a[i][l]] = min(e[a[i][j]][a[i][l]],ti);
				e[a[i][l]][a[i][j]] = min(e[a[i][l]][a[i][j]],ti);
			}
		}
	}
	lep(k,1,m){
		lep(i,1,m){
			lep(j,1,m){
				e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
			}
		}
	}
	lep(i,1,q){
		int u = rd(),v = rd();
		cout << e[u][v] + W[u] + W[v] << '\n';
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

cmd /c fc subway.out subway2.ans
*/
