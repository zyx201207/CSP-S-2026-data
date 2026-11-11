#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[5005][5005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=LONG_LONG_MAX;
			if(i==j)a[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int x[1005][2];// 0 dian 1 cost
		for(int j=1;j<=k;j++){
			cin>>x[j][0]>>x[j][1];
		}
		for(int z=1;z<=k;z++){
			for(int j=1;j<z;j++){
				a[x[z][0]][x[j][0]]=a[x[j][0]][x[z][0]]=x[j][1]+x[z][1];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<i;j++){
				if(i==k||k==j)continue;
				if((a[i][k]==LONG_LONG_MAX)||(a[k][j]==LONG_LONG_MAX))continue;
				a[j][i]=a[i][j]=min(a[j][i],min(a[i][j],a[i][k]+a[k][j]));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+a[x][y]<<"\n";
	}
	return 0;
}
