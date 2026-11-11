#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
const int N = 1e6+5, inf = 0x3f3f3f3f;

int C,T;
int n,m;
int u,v;
vector<int> vec[N]; 
int arr[N];
int dis[N];
int ans;
int pre[N];
bitset<N> vis;
set<int> se;
inline int find(int x){return x ? pre[x] = find(x) : x;}
inline void add(int x,int y){
	if (find(x)^find(y)){
		pre[find(x)] = find(y);
	}
}

inline void dfs(int x,int y){
	if (y > m)	return;
	if (x > n){
		if (y < m)	return;
		for(int i=1;i<=n;i++)	dis[i] = inf;
		for(int i=1;i<=m;i++)	dis[arr[i]] = 0;
		for(int p=1;p<=n;p++){
			for(int i=1;i<=n;i++){
				for(auto j:vec[i]){
					dis[i] = min(dis[i],dis[j]+1);
				}
			}
		}
		int tep = 0;
		for(int i=1;i<=n;i++){
//			cout << dis[i] << ' ';
			tep = max(tep,dis[i]);
		}
//		cout << endl;
		ans = min(ans,tep);
		return;
	}
	dfs(x+1,y);
	arr[y+1] = x;
	dfs(x+1,y+1);
}

inline void mian(){
	ans = inf;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	vec[i].clear();
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",ans);
}

signed main(){
	in(hub);
	out(hub);
	scanf("%d%d",&C,&T);
	while (T--)	mian();
	return 0;
}
/*

0 1
5 2
1 2
2 3
3 4
4 5

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/
