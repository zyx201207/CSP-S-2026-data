#include<bits/stdc++.h>
using namespace std;
#define lep(i,a,b) for(int i = a,ed##i = b;i <= ed##i; ++i)
#define rep(i,a,b) for(int i = a,ed##i = b;i >= ed##i; ++i)
int rd(){
	int res = 0,f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res * f;
}
const int N = 2e6 + 7,inf = 1e9;
typedef pair<int,int> pii;
int n,D,x[N],dis[N];
bool vis[N];
typedef pair<int,int> pii;
int path[N];
vector<pii> e[N];
void spfa(int s){
	queue<int> q;
	lep(i,1,n) dis[i] = inf,vis[i] = 0;
	q.push(s);
	vis[s] = 1,dis[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
//		cerr << u << '\n';
		vis[u] = 0;
		for(pii idx : e[u]){
			int v = idx.first,w = idx.second;
			if(dis[v] == dis[u] + w){
				path[v]++;
//				cerr << v << ' ' << path[v] << '\n';
				if(!vis[v]) q.push(v),vis[v] = 1;
				
			}
			if(dis[v] > dis[u] + w){
				path[v] = 1;
				dis[v] = dis[u] + w;
				if(!vis[v]) q.push(v),vis[v] = 1;
			}
		}
		
	}
}
void sol(){
	n = rd(),D = rd();
	lep(i,1,n) x[i] = rd();
	lep(i,1,n){
		lep(j,i+1,n){
			if(x[j] - x[i] > D) break;
			e[i].push_back({j,1});
			e[j].push_back({i,1});
		}
	}
	int ans = 0;
	spfa(1);
	lep(i,1,n) if(path[i] == 2)  ans++;
//	lep(i,1,n){
//		lep(j,1,n) path[i] = 0;
//		spfa(i);
//		lep(j,i + 1,n){if(path[j] == 2) ans++;}
//		lep(j,1,n) cerr << path[j] << ' ';
//		cerr << '\n';
//		lep(i,1,n) cerr << dis[i] << ' ';
//		cerr << '\n';
//		cerr << "ans" << ' ' << ans << '\n';
//	}
	cout << ans << '\n';
}
int main( void ){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Case = rd(),Test = rd();
	while(Test --) sol();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
