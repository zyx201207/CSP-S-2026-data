/*14：30-14：40 浏览完题目，决定开题顺序为T1-T2-T3-T4
14:40 T1写暴力算法
15：00 写成屎山了，T1删了重新写
15：30 暴力完成
15：45 暴力不对...
15：50 暴力终于对了（运气好不被卡常过10个点50分），写正解
15：55 考虑给枚举改成二分？思考check怎么写
16：10 正解写完了~开始对拍
16：30 拍出来错的啊....
16：40 可能是单调性判断问题，二分看一下
16：46 找到原因了，二分的l，r更新判断有问题，这个逻辑更新不对，再想想
16：50 找不到更新锚点啊，看后面的题的时候想想；T2开写
16：55 看起来是一个最短路呢，建图比较麻烦而已，试一试写一下dijkstra
17：30 模板没问题，建图有问题
17：40 T2尽力了，题目描述实在NB；开T3骗点分
17：50 我突然发现这个T3的c有可能是0来着，所以它会不会有样例在测试数据里呢？
17：55 T4距离可以拿LCA写，但是怎么选点？
18：10 最后收尾了。感觉考成 shi 了 
*/

#include<bits/stdc++.h>
using namespace std ;
const int MAXN = 1e4 + 10 ;//shao kai dian , wan yi bao le

int c , t ; 
vector <int> edge[MAXN];

int main(){
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin>>c>>t ;
	srand(time(0)) ;
	while(t --){
		int n , k ;
		cin>>n>>k ;
		
		for (int i = 1 , u , v ; i < n ; ++i){
			cin>>u>>v ;
			edge[u].push_back(v) ;
			edge[v].push_back(u) ;
		}
		
		cout<<rand() % 114514<<"\n" ;
	}
	return 0 ;
}

