#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn=1e3+20;
const int MAXX=1e9;
struct node{
	int v,w;
};
bool vis[maxn];
int ww[maxn];//进出站时间 
vector<int> xianlu[505];
vector<node> bc[maxn];
int xuu[maxn];
int line[505];//存储线路代表的节点 
ll ltl[505][505];//线路到线路 
vector<int> bel[maxn];
vector<int> xu;
ll d[505][505];
int cc,n,m,dd,q;
int cnt;//节点总数 
int main(){
//	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>cc>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
//		cout<<1;
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		xianlu[i].reserve(kk+2);
		for(int j=1;j<=kk;j++){
			int aa,tt;
			cin>>aa>>tt;
			bel[aa].push_back(i);
			if(!xuu[aa]){//该点不存在虚点 
				xuu[aa]=++cnt;
				xu.push_back(cnt);
			}
			bc[xuu[aa]].push_back({i,tt});
			bc[i].push_back({xuu[aa],tt});
		}
	}
	for(int i=1;i<=n;i++){
		line[i]=++cnt;
		for(int j:xianlu[i]){
			bc[line[i]].push_back({j,0});
			bc[j].push_back({line[i],0});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ltl[i][j]=MAXX;
			d[i][j]=MAXX;
		}
	}
	for(int i:xu){
		for(node j:bc[i]){
			for(node k:bc[i]){
				if(k.v==j.v){
					ltl[k.v][k.v]=0;
					continue;
				}
				ltl[j.v][k.v]=min(ltl[j.v][k.v],(ll)j.w+k.w);//ltl是连边，然后直接跑floyd 
				ltl[k.v][j.v]=ltl[j.v][k.v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
					cout<<d[i][j]<<endl;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
//		init();//一定别忘初始化
		int ss,tt;
		cin>>ss>>tt;//起点终点
		ll ans=MAXX;
		for(int l1:bel[ss]){
			for(int l2:bel[tt]){
				ans=min(ans,d[l1][l2]);
			}
		}
//		cout<<ans+ww[ss]+ww[tt]<<'\n';
	}
	return 0;
}
