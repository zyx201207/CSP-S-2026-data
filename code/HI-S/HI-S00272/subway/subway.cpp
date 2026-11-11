#include<bits/stdc++.h>
using namespace std;
int w[5000005];//每个站厅到地铁口的时间 
int a[505][25];//每条地铁经过的线路 
int b[505][5005];//每个站厅到地铁站台的时间 
int k[505];//每条地铁经过的线路的个数 
bool t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>b[i][a[i][j]];
	}
	while(q--){
		int x,y;cin>>x>>y;
		bool u=0,o=0;int sum=0;int g=0;bool f=0;
		for(int i=1;i<=n;i++){
			u=0,o=0;
			for(int j=1;i<=k[i];j++){
				if (a[i][j]==x){
					sum+=b[i][j];
					u=1;
				}
				if (a[i][j]==y){
					sum+=b[i][j];
					o=1;
				}
				if (u==1&&o==1){
					g=w[x]+w[y]+sum;
					cout<<g;
					f=1;
					break;
				}
			}
			if (f==1)break;
		}
		if (f==0)cout<<g;
	}
	return 0;
}
