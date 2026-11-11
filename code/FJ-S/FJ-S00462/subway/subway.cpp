#include<bits/stdc++.h>
using namespace std;
//分析题目这是一道模拟
//1行：输入c测试点编号没啥用,n线路,m地铁站数,d最多经过站数不知道有啥用,q计划数
//2行：每个站进出时间
//3+n行：第一个表示数量地铁线路经过站+从地铁厅进站的时间
//3+n+q行：计划
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//第一条线1 2 4第2条2 3 5
//先找一步到位的发现没有要到3就要到2
//只有1条线可以到达1 2 2 3计算完毕
//第二个样例
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//作图后发现入度都唯一单一线路
//怎么做?
//模拟作图or广搜
//我先试试广搜n<500邻接矩阵耍起"夫若亿得"加强版但我不会写froyid化图发广搜lets go
//实在不行还能骗分
int tu[510][510],x,y;
struct Node{
	int zhan,tt;
}k[500010];
int c,n,m,d,q;
int mt[510];
void bfs(int now,int last,long long step){
//	cout<<"@"<<now<<" "<<last<<" "<<step<<endl;
//	cout<<now<<endl;
	if(now==y){
		cout<<step+mt[y];
		return;
	}
	for(int i=1;i<=n;i++){
		if(tu[now][i]!=0&&now!=i){
			bfs(i,x,step=step+tu[now][i]+tu[i][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	ios::sync_with_stdio(false);//加速防爆
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mt[i];
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>k[j].zhan>>k[j].tt;
//			cout<<k[j].zhan<<" "<<k[j].tt<<" "<<j<<"!"<<endl;	
		}
		for(int j=1;j<=k1;j++){
			for(int t=j;t<=k1;t++){
				tu[k[j].zhan][k[t].zhan]=k[t].tt;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<tu[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		bfs(x,x,mt[x]);
	}
	freopen("subway.out","w",stdout);
	return 0;
}