#include<iostream>
#include<vector> 
#include<queue>
#define mp make_pair
#define pa pair<int,int>
using namespace std;
const int si=1e3+10,sj=510;
int wobushiai;
int n,m,d,q;
//n->线路数,m->站数,q->出行计划数 
int w[si],k[sj];
//wi->地铁口到站厅时间,ki->此线路站数
vector<int>a[sj],t[sj];
//ai,j->i线路的第j个站编号 
//ti,j->i线路的第j个站站厅到i线路站台所需时间
struct node{
	int v,w;
};
vector<node> e[si],h[si];
int dis[si];
priority_queue<pair<int,pa>> st;
bool vis[si];
void dij(int start){
	
}
int main(){
	cin>>wobushiai;
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int i1,i2,la=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&i1,&i2);
			if(la)e[la].push_back({i1,0}),e[i1].push_back(la);
			h[i1].p
		}
	}
	
	return 0;
}















/*
14:54我的天，我在10.28的宿舍卧谈会出过这个题
14:55其实还是有点不同，难道我是预言家？ 
15:01好乱，让我注释一下 
15:21没啥思路呢，但好像换乘站数量不会很大？
15:26并非 
15:36先拿部分分吧
16:01好难调啊先看下一题吧
18:13又回来了，不想写了，这不仅模拟还算法，难难？！ 
*/
