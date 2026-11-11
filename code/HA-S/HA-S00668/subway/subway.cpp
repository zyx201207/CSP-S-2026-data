#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn=5e5+5;
const long long MAXX=1e18+5;
struct node{
	int v,w;
	bool operator<(const node&a)const{
		return a.w<w;
	}
};
ll dis[maxn];
bool vis[maxn];
int ww[maxn];//进出站时间 
priority_queue<node> pq;
vector<int> xianlu[505];
vector<node> bc[maxn];
int xuu[maxn];
int cc,n,m,d,q;
int cnt;//节点总数 
void init(){
	while(!pq.empty()){
		pq.pop();
	}
	for(int i=1;i<=cnt;i++){
		dis[i]=MAXX;
		vis[i]=false;
	}
}
int dijk(int s,int t){
	dis[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		node tp=pq.top();
		pq.pop();
		if(vis[tp.v]){
			continue;
		}
		vis[tp.v]=true;
		for(auto i:bc[tp.v]){
			int v=i.v,w=i.w;
			if(dis[v]>dis[tp.v]+w){
				dis[v]=dis[tp.v]+w;
				pq.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		xianlu[i].reserve(kk+2);
		for(int j=1;j<=kk;j++){
			int aa,tt;
			cin>>aa>>tt;
			if(!xuu[aa]){//该点不存在虚点 
				xuu[aa]=++cnt;
			}
			xianlu[i].push_back(++cnt);
			if(j>1){
				bc[cnt].push_back({xianlu[i][j-2],0});
				bc[xianlu[i][j-2]].push_back({cnt,0});	
			}
			bc[xuu[aa]].push_back({cnt,tt});
			bc[cnt].push_back({xuu[aa],tt});
		}
	}
	for(int i=1;i<=q;i++){
		init();//一定别忘初始化
		int ss,tt;
		cin>>ss>>tt;//起点终点
		cout<<dijk(xuu[ss],xuu[tt])+ww[ss]+ww[tt]<<'\n';
	}
	return 0;
}
