#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,ppp,b[500009],f[509][509];
struct Node{
	int b,c;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ppp>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		Node a[509];
		for(int j=1;j<=p;j++){
			int u,v;
			cin>>u>>v;
			a[j].b=u,a[j].c=v;
			f[u][u]=v;
		}
		for(int j=1;j<=p-1;j++){
			for(int k=j+1;k<=p;k++){
				f[a[j].b][a[k].b]=f[a[k].b][a[j].b]=min(f[a[j].b][a[k].b],a[j].c+a[k].c);
			}
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=i+1;k<j;k++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+b[x]+b[y]<<endl;
	}
	return 0;
}
