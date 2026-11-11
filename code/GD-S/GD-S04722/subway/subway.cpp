#include<iostream>
using namespace std;

// c没用  n < 500 | m < 1e9 | ki < 5e5 | d < 20 | q < 1e5 
// wi < 1e9 | aij < 1e9 | tij < 1e9
// 

int main(){
	// c n线路数 m站数 d站最多线数 q计划数
	// wi口到厅时间 ki线i经过站数 aij线i从j-1到j站时间
	// tij登车时间 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[1000],k[1000],a[100][100],t[100][100];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	return 0;
}
