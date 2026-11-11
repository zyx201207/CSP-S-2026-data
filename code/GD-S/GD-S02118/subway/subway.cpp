#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=100001;
struct node{
	int a;//地铁站编号
	int t;//从站厅--站台所用时间 
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;//测试点编号,路线数,站数,每个地铁站最多被几条线路经过,出行计划数
	int w[N];
	for(int i=1;i<=m;i++)cin>>w[i];
	int k[510];//经过的地铁站数
	node s[N];//
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++)cin>>s[j].a>>s[j].t;
	}
	int x[M],y[M];
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int sum=w[x[i]]+w[y[i]];
		int x1[510],y1[510];//经过起点(x)终点(y)路线编号， 
		for(int j=1;j<=n;j++){
			for(int z=1;z<=k[i];z++){
				
			}
		}
		
	}
	
	return 0;
} 
//进入：站口--站厅--站台
//换乘：站厅--站台
//出去：站台--站厅--站口 
