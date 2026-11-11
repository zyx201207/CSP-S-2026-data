#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[500050];
long long dis[510][510],ans;
vector<pair<int,int> > ptol[500050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>f[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		while(len--){
			int x,y;
			cin>>x>>y;
			ptol[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	}
	//cerr<<"part 1 :"<<clock()<<'\n';
	for(int i=1;i<=m;i++){
		int len=ptol[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int x=ptol[i][j].first,y=ptol[i][k].first;
				long long xw=ptol[i][j].second,yw=ptol[i][k].second;
				dis[x][y]=min(dis[x][y],xw+yw);
			}
		}
	}
	//cerr<<"part 2 :"<<clock()<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			long long w=min(dis[i][j],dis[j][i]); 
			dis[i][j]=dis[j][i]=w;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//cerr<<"part 3 :"<<clock()<<'\n';
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=3e18;
		for(auto i:ptol[x]){
			for(auto j:ptol[y]){
				ans=min(ans,i.second+dis[i.first][j.first]+j.second);
			}
		}
		ans+=(f[x]+f[y]);
		cout<<ans<<'\n';
	}
	//cerr<<"part 4 :"<<clock()<<'\n';







	return 0;
}

/*

地铁站 - 站厅 是 w

站厅 - 线路站台是 t
 
线路经过的站 a 

可能有“站内换乘”，不会到地铁站，但是要到站厅

注意，不算坐车的时间，也没有给出

只看走路的时间

首先 w 没用，这是必须加的，先加上

d 有什么用

这玩意是不是等效于最短路

我们显然可以有一个 sum ki 点数，并同阶边数的最短路做法

这样差不多能过前 15 个点


n 是地铁线路的数量，m 是地铁站的数量

那么你进站，一定会进一个地铁线路

用一个超级点处理

一个地铁站可以视为中转点，连接不同的地铁线路

只要可以处理出地铁线路的全源最短路即可

算法流程：首先读入先加上 w

然后枚举走进的地铁线路，d^2 

要求最短路

关于建图就是每个地铁站会 d^2 枚举对

然后先 floyd 掉

这题样例数据还是不满，需要拍拍 + 卡常！ 

还要小心 longlong 


15:12 地铁是双向的 

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

一遍过？

subway.exe < subway1.in > subway1.out
subway.exe < subway2.in > subway2.out
subway.exe < subway3.in > subway3.out
subway.exe < subway4.in > subway4.out
subway.exe < subway5.in > subway5.out
subway.exe < subway6.in > subway6.out
subway.exe < subway7.in > subway7.out
fc subway1.ans subway1.out
fc subway2.ans subway2.out
fc subway3.ans subway3.out
fc subway4.ans subway4.out
fc subway5.ans subway5.out
fc subway6.ans subway6.out
fc subway7.ans subway7.out 

D:\CQ-S00206>subway.exe < subway1.in > subway1.out
part 1 :0
part 2 :0
part 3 :0
part 4 :0

D:\CQ-S00206>subway.exe < subway2.in > subway2.out
part 1 :15
part 2 :15
part 3 :15
part 4 :15

D:\CQ-S00206>subway.exe < subway3.in > subway3.out
part 1 :15
part 2 :15
part 3 :15
part 4 :15

D:\CQ-S00206>subway.exe < subway4.in > subway4.out
part 1 :0
part 2 :0
part 3 :46
part 4 :78

D:\CQ-S00206>subway.exe < subway5.in > subway5.out
part 1 :0
part 2 :0
part 3 :62
part 4 :62

D:\CQ-S00206>subway.exe < subway6.in > subway6.out
part 1 :78
part 2 :78
part 3 :124
part 4 :156

D:\CQ-S00206>subway.exe < subway7.in > subway7.out
part 1 :109
part 2 :109
part 3 :156
part 4 :203

D:\CQ-S00206>fc subway1.ans subway1.out
正在比较文件 subway1.ans 和 SUBWAY1.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway2.ans subway2.out
正在比较文件 subway2.ans 和 SUBWAY2.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway3.ans subway3.out
正在比较文件 subway3.ans 和 SUBWAY3.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway4.ans subway4.out
正在比较文件 subway4.ans 和 SUBWAY4.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway5.ans subway5.out
正在比较文件 subway5.ans 和 SUBWAY5.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway6.ans subway6.out
正在比较文件 subway6.ans 和 SUBWAY6.OUT
FC: 找不到差异


D:\CQ-S00206>fc subway7.ans subway7.out
正在比较文件 subway7.ans 和 SUBWAY7.OUT
FC: 找不到差异
*/

