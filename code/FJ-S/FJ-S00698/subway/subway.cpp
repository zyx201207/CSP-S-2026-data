#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#define N 505
using namespace std;

int c, n, m, d, q;
long long w[N], dis[N];
struct Node{
	int u, v, t;
};
vector<Node> st[N];
queue<Node> p;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=m;i++){
		scanf("%lld", &w[i]);
	}
	int k, id, te;
	for(int i=m+1;i<=m+n;i++){
		scanf("%d", &k);
		while(k--){
			scanf("%d%d", &id, &te);
			st[i].push_back({i, id, te});
			st[id].push_back({id, i, te});
		}
	}
	int x, y;
	while(q--){
		memset(dis, 0x3f, sizeof(dis));
		scanf("%d%d", &x, &y);
		dis[x]=0;
		for(auto i:st[x]){
			p.push(i);
//			printf("%d %d %d\n", i.u, i.v, ind1[i.v]);
		}
		while(!p.empty()){
			Node now=p.front();
//			printf("%d\n", now.v);
			p.pop();
//			printf("%d %d %d\n", now.u, now.v, dis[now.u]+now.t);
			long long old=dis[now.v];
			dis[now.v]=min(dis[now.v], (dis[now.u]+(long long)now.t));
			for(auto i:st[now.v]){
//				printf("%d %d %d\n", i.u, i.v, ind1[i.v]);
				if(old > dis[now.v]){
					p.push(i);
				}	
			}
		}
//		for(int i=1;i<=m+n;i++){
//			printf("%d ", dis[i]);
//		}
//		printf("\n");
		printf("%lld\n", dis[y]+w[x]+w[y]);
	}
	
	return 0;
}
