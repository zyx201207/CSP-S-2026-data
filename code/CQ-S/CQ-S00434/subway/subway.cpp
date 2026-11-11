#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Quirrel{
//tmp
int x,y;
pair<int,int>p1,p2;
//input
int cc,n,m,d,q,a[500100],k[600];
vector<pair<int,int> >g[500100];
//graph
int f[600][600];
const int inf=1e18;
//output
int ans;
signed main(){
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=inf;
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				p1=g[i][j];p2=g[i][k];
				f[p1.first][p2.first]=f[p2.first][p1.first]=min(f[p1.first][p2.first],p1.second+p2.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			} 
		}
	}
	while(q--){
		cin>>x>>y;ans=inf;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,g[x][i].second+f[g[x][i].first][g[y][j].first]+g[y][j].second);
			}
		}
		ans+=a[x];ans+=a[y];cout<<ans<<"\n";
	}
	return 0;
}
//
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Quirrel::main();
	return 0;
}
/*
更正通知：地铁双向通行 

还好我的笔记复习到位了
有一个非常类似的trick
就是说DP不一定要DP看起来需要DP的
一些看起来不能DP的往往是关键
n不大
又是多源最短路 
Floyd
建图的话就利用d<=20这个性质

赵若涵保佑我不要挂分

We are all in the gutter,but some of us are looking at the stars. 
*/
