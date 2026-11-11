#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//m是地铁站数，n是地铁线路数，c是测试点号，d是地
//铁站最多出现的次数，q相当于数据组数； 
	int w[m+1];//w[i]表示从i站到站厅的位置 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a[m+1][n+1];//a[i][j]表示第 i 条线路经过的第j 个地铁站的编号 
	int t[m+1][n+1];//t[i][j]表示从a[i][j]站厅走到第i条线的时间
	//也就是说，n+1，j两者意思（位置上看）相同！ 
	for(int i=1;i<=n;i++){
		int k;cin>>k;//k就是作为提示你信息量的东西 
		k*=2;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];//根据前文的结论得出 
		}
	}
	int aim[q][2];//用来存储数据组数，aim[i][0]意思是第i组数据起点为 
	for(int i=1;i<=q;i++){
		int b,e;
		cin>>b>>e;
		if(b>e){
			int z;
			z=b;
			b=e;
			e=z;
		} //这里强制让起点编号一定小于终点，原理是在这个图中无方向1->2
		//和2->1所用时间相同，故而； 
		aim[i][0]=b;
		aim[i][1]=e;
	}
	for(int i=1;i<=q;i++){
		bool lia[m];
		if((m==2&&n==1)||m==1){
			cout<<0<<endl;
		}
		
		if(c>=7&&c<=11){
			while(q--){
				
			}	
		}		
	}

	
}
