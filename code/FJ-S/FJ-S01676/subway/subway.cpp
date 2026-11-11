#include<bits/stdc++.h>
using namespace std;
int a[501][500010];
int t[501][500010];
int k[501];
int x[500010];
int y[500010];
int c,n,m,d,q;long long w[500005];
	//----- 创建 -----// 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//c测试点编号
	//n地铁线路数
	//m地铁站数
	//d每个地铁站最多被几条线路经过
	//q出行计划数
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}	
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	//----- 输入 -----//
	
	 
	return 0;
} 
