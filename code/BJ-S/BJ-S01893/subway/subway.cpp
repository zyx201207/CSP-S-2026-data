#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
struct node {
	long long v;int num;
};
long long a[maxn];
node g[maxn][maxn];	
int c,n,m,d1,q;
int b[maxn][maxn];
long long ans=0;
int st,ed;
node f[maxn][maxn];
int fcnt[maxn];
node zc[maxn][maxn];
int build(int numi){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			zc[i][j]=g[i][j];
			//(g[i][j].v==1e18?cout<<"0 ":cout<<g[i][j].v<<" ");
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		if(g[st][i].num!=numi){
			g[st][i].num=0;
			g[st][i].v=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(g[i][k].num!=0&&g[k][j].num!=0){
					if(g[i][k].num!=g[k][j].num&&g[i][k].v+g[k][j].v+b[g[j][k].num][k]<g[i][j].v){
						g[i][j].v=g[i][k].v+g[k][j].v+b[g[k][j].num][k];
						//cout<<i<<k<<j<<b[g[j][k].num][k]<<"\n";
						g[i][j].num=g[k][j].num;
					}else if(g[i][k].num==g[j][k].num){
						g[i][j].v=0;
						g[i][j].num=g[i][k].num;
					}
				}
			}
		}
	}
	long long ret=b[numi][st]+g[st][ed].v+a[st]+a[ed];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			//(g[i][j].v==1e18?cout<<"0 ":cout<<g[i][j].v<<" ");
			g[i][j]=zc[i][j];
		}
		//cout<<"\n";
	}
	return ret;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			g[i][j].v=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int ly=0;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			g[ly][y]={z,i};
			f[y][++fcnt[y]]={ly,i};
			b[i][y]=z;
			ly=y;
		}
	}
	while(q--){
		cin>>st>>ed;
		long long ans=1e18;
		for(int i=1;i<=fcnt[st];i++){
			long long re=build(f[st][i].num);
			ans=min(ans,re);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
