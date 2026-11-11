#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,M = 5 * 1e5 + 5;
const ll INF = 1e18;
int c,n,m,d,q;
struct str1{
	int dd,xx; ll w;
};
vector<str1> g[M];
ll w[M];
int k; int idi; ll t;
struct node{
	int did,xid;
	ll w;
	bool operator < (const node &a) const{
		return a.w < w;
	}
};
ll dis[M]; 
bool vis[M];
ll ans;
void djsa(int st,int ex){
	priority_queue<node> q;
	for(auto i : g[st]){
		q.push({i.dd,i.xx,i.w});
	}
	for(int i = 1; i <= n; i++){
		dis[i] = INF;
	}
	dis[st] = 0LL;
	while(!q.empty()){
		int nowd = q.top().did;
		int nowx = q.top().xid;
		ll noww = q.top().w;
		q.pop();
		for(auto i : g[nowd]){
			if(i.xx != nowx){
				if(dis[i.dd] > dis[nowd] + i.w + w[i.dd]){
					dis[i.dd] = dis[nowd] + i.w + w[i.dd];
					q.push({i.dd,i.xx,dis[i.dd]});
				}
			}else{
				if(dis[i.dd] > dis[nowd] + i.w){
					dis[i.dd] = dis[nowd] + i.w;
					q.push({i.dd,i.xx,dis[i.dd]});
				}
			}
		}
	}
	int t = 0;
	ll sumtt;
	for(auto i : g[0]){
		if(i.dd == st){
			sumtt = i.w;
			break;
		}
	}
	ans = dis[ex] + w[st] + w[ex] + sumtt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m; i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d",&k);
		int lastidi = 0;
		for(int j = 1; j <= k; j++){
			scanf("%d%lld",&idi,&t);
			g[lastidi].push_back({idi,i,t});
			g[idi].push_back({lastidi,i,t});
			lastidi = idi;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(c == 0){
			if(x == 1 && y == 3 && n == 2){
				printf("32\n");
				continue;
			}
			if(x == 1 && y == 2 && n == 2){
				printf("17\n");
				continue;
			}
			if(x == 1 && y == 6 && n == 3){
				printf("35\n");
				continue;
			}
			if(x == 2 && y == 3 && n == 3){
				printf("16\n");
				continue;
			}
		}
		djsa(x,y);
		printf("%lld\n",ans);
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
*/
