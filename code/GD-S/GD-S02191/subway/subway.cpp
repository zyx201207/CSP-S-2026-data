//0 2 5 20 2
//4 1 9 2 5
//
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//c=0	  无关 
//n=2   地铁线路数 
//m=5	  地铁站数 
//d=20  第i条经过站数MAX 
//q=2	  出行计划数
//
//w[1]=4 w[2]=1 w[3]=9 w[4]=2 w[5]=5
//分别表示从第i个地铁站的地铁口走到站厅需要的时间
//	|
//	|___从第一个地铁站的地铁口走到站厅需要4
//	    从第二个地铁站的地铁口走到站厅需要1
//		从第三个地铁站的地铁口走到站厅需要9
//		从第四个地铁站的地铁口走到站厅需要2
//		从第五个地铁站的地铁口走到站厅需要5
//
//   						  a t   a t   a t
//(i==1)=> k[1]=3 a[1][j]=>{1 5} {2 7} {4 6}
//		从第一线路第1个地铁口走到站厅需要5		
//		从第一线路第2个地铁口走到站厅需要7
//		从第一线路第4个地铁口走到站厅需要6
//(i==2)=> k[2]=3 a[2][j]=>{2 3} {3 4} {5 7}
//		从第二线路第2个地铁口走到站厅需要3	
//		从第二线路第3个地铁口走到站厅需要4
//		从第二线路第5个地铁口走到站厅需要7
//
// 

#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c,n,m,d,q;
int k[N],w[N],sum_k=0;
vector<pair<int,int>> a[N];
vector<pair<int,int>> g[N];
int x[N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		sum_k+=k[i];
		for(int j=1;j<=k[i];j++){
			int from,time;
			cin>>from>>time;
			a[i].push_back({from,time});
			
		}
	}
	
	for(int i=1;i<=n;i++){
		int js=0;
		for(auto e:a[i]){
			x[++js]=e.first;
		}
		for(int u=1;u<=js;u++){
			if(x[u+1]!=0) {
				g[x[u]].push_back({x[u+1],0});
				g[x[u+1]].push_back({x[u],0});
			}
		}
	}
	int sum_size=0;
	for(int i=1;i<=m;i++){
		for(auto e:g[i]){
			sum_size++;
		}
	}
	int sumsum=0;
	for(int i=1;i<=n;i++){
		int js=0;
		
		for(int u=1,k=1;u<=sum_k;u++){
			for(auto e:a[u]){
				x[++js]=e.second;
			
			}
			g[k].push_back({sum_size+u,x[u]});
			g[sum_size+u].push_back({k,x[u]});
			sumsum=max(sumsum,sum_size+u);
		}
	}
//	for(int i=1;i<=n)
	for(int i=1;i<=m;i++){
		for(auto e:g[i]){
			cout<<i<<"->"<<e.first<<' '<<e.second<<endl;
		}
	}
	cout<<sumsum;
//	while(q--){
//		int x,y;
//		cin>>x>>y;
//		
//		
//	}
	return 0;
}
