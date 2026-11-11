#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500100],k[510];
int a[510][500100];
int t[510][500100];
int x[500100],y[500100];
//a[i][j]第i线路经过的第j个站号
//t[i][j]第j号站到i线站台时间
//k[i]第i线有多少个站
//c测试点号 n线路数量 m站数 d最多几条线过一个站 q问题数 

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][(j/2)+1]>>t[i][(j/2)];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
}
