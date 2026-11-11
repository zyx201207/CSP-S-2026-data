#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
int test,T;
int n,d;
int x[N];
struct edge{
	int v,w;
};
vector<edge> g[N];
struct node{
	int u,dist;
};
queue<node> q;
int bfs(int sx,int ex){
	q.push({sx,0});
	int minn=INT_MAX,ans=1;
	while(!q.empty()){
		int u=q.front().u,dist=q.front().dist;
		q.pop();
		if(u==ex){
			cout<<minn<<' '<<dist<<' '<<ans<<'\n';
			if(minn>dist){
				minn=dist;
				ans=1;
			}
			else if(minn==dist)
				ans++;
			continue;
		}
		int cnt=1;
		for(int i=g[u].size()-1;i>=0&&cnt<=2;--i,++cnt){
			int v=g[u][i].v,w=g[u][i].w;
			if(x[v]>x[ex]) continue;
			q.push({v,dist+w});
		}
	}
	return ans==2;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n=4,d=2;
	for(int i=1;i<=n;++i) x[i]=x[i-1]+1;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j)
			if(x[j]-x[i]<=d){
				g[i].push_back({j,x[j]-x[i]});
			} else break;
	}
	cout<<bfs(1,4);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
-----
1
2
*/
