#include<bits/stdc++.h>
using namespace std;
const int D = 22,N = 505; 
int c,n,m,d,q; // n边数 m点数 d每个点最多的边数 
int leave[N];
struct steel{
	int zhan,shu;
}; 
struct line{
	int to,v;
};
struct node{
	int diss,st;
	operator <(const node& x) const{return diss < x.diss;}
};
bool cmp(node x,node y){
	return x.diss < y.diss;
}
vector<line> g[D];
void dij(int x,int y){
	priority_queue<node> que;
	int dis[m+5],vis[m+5] = {0};
	memset(dis,0x3f,sizeof dis);
	node xxx;
	xxx.diss = 0;
	xxx.st = x;
	que.push(xxx);
	dis[x] = 0;
	while(!que.empty()){
		node topp = que.top();
		que.pop();
		int qidian = topp.st;
		if(vis[qidian]) continue;
		vis[qidian] = 1;
		for(auto lu : g[qidian]){
			int w = lu.to,zhongdian = lu.v;
			if(dis[zhongdian] > dis[qidian] + w){
				dis[zhongdian] = dis[qidian] + w;
				que.push({dis[zhongdian],zhongdian});
			}
		}
	}
	cout << dis[y]+leave[x]+leave[y] << endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) 
		cin >> leave[i];
	for(int i = 1;i <= n;i++){
		int nn;cin >> nn;
		vector<steel> f(nn+5);
		for(int j = 1;j <= nn;j++){
			cin >> f[j].zhan >> f[j].shu;
		}
		for(int i = 1;i <= nn;i++){
			for(int j = 1;j < i;j++){
				g[f[i].zhan].push_back({f[i].shu+f[j].shu,f[j].zhan});
				g[f[j].zhan].push_back({f[i].shu+f[j].shu,f[i].zhan});
			}
		}
	}
	while(q--){
		int xr,yr;cin >> xr >> yr;
		dij(xr,yr);
	}
		
	return 0;
}

