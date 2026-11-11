#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int k[505],k1[100005];
int w[500005];
int x[100005],y[100005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin >> c >> n >> m >> d >> q ;
	for (int i=1;i<=m;i++) {
		cin >> w[i];// m 个正整数 w 1 ,w 2 ,...,w m ，依次表示从每个地铁站的地铁口走到站厅需要的时间。
	}
	for (int i=1;i<=n;i++) {
		cin >> k[i];
		for (int j=1;j<=2*k[i];j++)  cin >>  k1[j];
 	}
 	for (int i=1;i<=q;i++) {
 		cin >> x[i]  >> y[i];	
	}
	for (int i=1;i<=q;i++) {
		cout << w[i]*(y[i]-x[i]); 
	}
	//对于所有线路经过的所有地铁站，从站厅走到对应线路站台的步行时间都相同，即存在正整数 T，使得对于所有 i,j (1 ≤ i ≤ n, 1 ≤ j ≤ k i )，均有 t i,j = T。
	return 0; 
}
