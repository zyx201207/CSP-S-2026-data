#include <bits/stdc++.h>
using namespace std;

const int X=1e9+1;

//c=测试点编号(?); t=测试组数 
int c,t;
//n=一组数据中的城市数量; k=一组数据中的基地数量 
long long n,k;
//u[x]、v[x]分别表示第i条道路连接的两座城市的编号
long long u[X],v[X];
long long p[X];

int main(){
	//规定输入输出
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	//输入基本量
	cin>>c>>t;
	
	//设置答案变量
	long long R_min=1e9+15;//开到趋近无穷大 
	//对每组数据进行"输入+处理+输出"复合操作
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++)
			cin>>u[j]>>v[j];
		//计算每座城市之间的边数 
		for(int j=1;j<n;j++){
			for(int l=1;l<n;l++)
				if(u[l]==j||c[l]==j) 
					p[j]++; 
		
			//d(i)=min_j∈S dist(i,j)
			//dist(i,j) 表示从第i座城市到第j座城市所需经过的道路的最少条数
			//先假定每一座城市都可以建造基地
			//再根据题设条件进行排除，得到最终符合数量的基地方案 
			//最后考虑通勤距离和通勤半径 
			//核心部分：通勤半径？ 
			for(int p=1;p<=n;p++){
				//先对不合题意的城市进行排除 
			} 
		} 
		
		//输出
		cout<<R_min<<endl; 
	} 
	
	return 0;
}
