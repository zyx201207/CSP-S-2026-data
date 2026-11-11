#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e6+5;
int cas,t,n,d;
int a[N],dis[N];
vector<int> e[N]; 
//先求最短路长度，再bfs统计path num 
struct node{
	int id,stp;
};
int dij(int sx,int y){
	queue<int> q;
	for(int i = 1;i<=n;i++) dis[i] = -1;
	q.push(sx); 
	dis[sx] = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
//		cout<<u<<'\n';
		for(auto v : e[u]){
//			cout<<"jinV\n";
//			cout<<v<<' '<<dis[v]<<'\n';
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[y];
}
int calc(int x,int y){
	int mn_d = dij(x,y);
	queue<node> q;
	q.push({x,0});
	dis[x] = 0;
	int res = 0;
	while(!q.empty()){
		node tmp = q.front();q.pop();
		int u = tmp.id,step = tmp.stp;
		if(u==y&&step==mn_d){
			res++;
			continue;
		}
		for(auto v : e[u]){
			q.push({v,step+1});
		}
	}
	return res;
}
void solve(int n){
	int ans = 0;
//	cout<<n<<'\n'; 
	for(int i = 1;i<=n;i++){
//		cout<<i<<'\n';
		for(int j = i+1;j<=n;j++){
//			cout<<"*\n";
//			cout<<i<<' '<<j<<' '<<calc(i,j)<<'\n';
			if(calc(i,j)==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cas>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i<=n;i++){
			e[i].clear();
			scanf("%lld",&a[i]);
		}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
//				cout<<dij(i,j)<<'\n';
				if(a[j]-a[i]<=d){
					e[i].push_back(j);//直接单向 
				}
			}
		}
//		for(int i = 1;i<=n;i++){
//			for(int j = i+1;j<=n;j++){
//				int x = dij(i,j);
////				printf("i: %lld j: %lld dij: %lld\n",i,j,x);
//			} 
//		}
		solve(n);
	}
	return 0;
}
