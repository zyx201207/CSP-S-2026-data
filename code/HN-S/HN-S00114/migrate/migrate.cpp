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
	int minn=INT_MAX,ans=0;
	while(!q.empty()){
		int u=q.front().u,dist=q.front().dist;
		q.pop();
		if(u==ex){
			cout<<minn<<' '<<dist<<' '<<ans<<'\n';
			if(minn>dist){
				minn=dist;
				ans=0;
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
	cin>>test>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>x[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)
				if(x[j]-x[i]<=d){
					g[i].push_back({j,x[j]-x[i]});
				} else break;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(bfs(i,j)){
					ans++;
//					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
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

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
-----
0
1
*/
