#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 505
#define M 500005
#define INF 0x3f3f3f3f3f3f3f3fll

struct edge{
	int to,t;
};
struct sta{
	vector<edge> e;
	int v;
}s[M];//存储站点连接哪条线以及各种权值 

ll dis[N][N];//floyd距离数组 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].v;
	}
	memset(dis,0x3f,sizeof dis);//初始化为无限大
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int a,t;
			cin>>a>>t;
			for(int k=0;k<s[a].e.size();k++){
				dis[s[a].e[k].to][i]=dis[i][s[a].e[k].to]=s[a].e[k].t+t;//s[a]站点的e[k]边通向的to线路与i线路的距离 为 s[a]站点与to线路的距离加上s[a]站点到i线路的距离 
			}
			s[a].e.push_back({i,t});
			//cout<<a<<" "<<i<<" "<<t<<'\n';//debug
			//cout<<s[a].e.size()<<'\n';//debug
			//这神人代码也就我能写出来了 
		}
	}
	//既然我们建好边了，那就来跑一个可爱的floyd吧
	//问题是我们真的忘记了floyd怎么写
	//现场推一下吧q_q
	//奋战30min写出来了，我是fw
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}//debug
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}//debug
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		ll base=s[x].v+s[y].v;
		ll ans=INF;
		//cout<<s[x].e.size()<<" "<<s[y].e.size()<<'\n';//debug
		for(auto u : s[x].e){
			for(auto v : s[y].e){
				ans=min(ans,u.t+v.t+dis[u.to][v.to]);
			}
		}
		cout<<base+ans<<'\n';
	}
	return 0;
}
/*
显然我们可以注意到可以建一个图：
每个地铁站连接着它们的出口，边权已经给出 
每条地铁线路链接所有它能到的站，每个边权已经给出
得到结点数2*m+n个，边m+K条，显然丰富的超了
我不管，等到2小时再开始写暴力，先想想
万一
48万个站点，这城市真牛逼！6767676767676767
看起来这个方案真的不太可行 
能不能看成线到线的距离，反正我们的入站出站一定要有
这真是一个好想法！
那么d<=20的用处我们知道了，复杂度里有一个d2
We are going to find the distance between every lines.
Edges can be constructed like this:
编不下去了

总之我们完全可以编出一系列以地铁线路为顶点的图
结点数500，边数最坏125000 显然不能用dij只能floyd
n3完全可以接受的预处理后，我们可以O1获取，这多是一件美事
每次查询我们遍历一下可以选择的起始线路和终点线路
每次便利查一下线路距离，然后再查一下线路到站厅，再最小值一下
线路到站厅怎么办
500000个站点，500个线路
250000000个整数可以吗
250000000*4=1000000000
1000000000/1048576 约等于 953MB 
XD这可太极限了
floyd加上500*500
存站点有几条相邻线路20*500000
等等我们根本不需要这样，在可爱的站点存边顺便把长度存一下就OK了
我是梳篦
虽然原来的梳篦做法好像也不会爆炸
复杂度O(n^3 + q(d^2))，能过
开干
对了，floyd怎么写 
哦，给地铁线路之间建边也要n(d^2)，不过不会爆炸 
*/
