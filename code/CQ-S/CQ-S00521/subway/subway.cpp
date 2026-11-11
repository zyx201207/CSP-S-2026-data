#include <bits/stdc++.h>
using namespace std;
namespace yhy{
	#define int long long
	const int MAXN=500+5;
	const int MAXM=5e5+5;
	const int INF=1e18;
	int opt,n,m,d,Q;
	int w[MAXM+5];
	struct node{ int to,val; };
	vector<node> G[MAXM+5]; // 第 i 个地铁站连接了哪些地铁线路
	vector<node> vt[MAXN+5]; // 地铁线路条数 我也不知道记录这个能干吗 反正敲键盘敲着爽就完了
	int dis[MAXN+5][MAXN+5];
	int len[MAXN+5];
	// 相当于是把一条地铁线路变成了一个点
	int main() {
		cin>>opt>>n>>m>>d>>Q;
		for(int i=1;i<=m;i++) cin>>w[i];	
		for(int i=1;i<=n;i++) {
			cin>>len[i];
			for(int j=1;j<=len[i];j++) {
				int x,y; cin>>x>>y;
				G[x].push_back({i,y});
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j) continue;
				dis[i][j]=INF;
			}
		}
		for(int i=1;i<=m;i++) {
			for(auto p:G[i]) {
				for(auto q:G[i]) {
					dis[p.to][q.to]=min(dis[p.to][q.to],p.val+q.val);
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				for(int k=1;k<=n;k++) {
					if(dis[j][i]+dis[i][k]<=dis[j][k]) {
						dis[j][k]=dis[j][i]+dis[i][k];
					}
				}
			}
		}
		while(Q--) {
			int x,y; cin>>x>>y;
			int ans=INF;
			for(auto p:G[x]) {
				for(auto q:G[y]) {
					ans=min(ans,p.val+q.val+dis[p.to][q.to]);
				}
			}
			ans+=w[x]+w[y];
			cout<<ans<<'\n';
		}
		return 0;
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	yhy::main();
	// cerr<<"clock():"<<clock()<<'\n';
	return 0;
}
/*
恶趣味出题人
喜欢放诡异题目来搞选手
容易发现可以把一条线路变成一个点
这个 d<=20 是来干啥的
怎么有个 1<=M<=5e5 的限制
那我知道 d<=20 是来干啥的了
4e7 感觉能过
500 次 dij 跑不了
但是我可以直接 20*20*500 建边
哦我还不能跑 dij，必须 floyd
*/
