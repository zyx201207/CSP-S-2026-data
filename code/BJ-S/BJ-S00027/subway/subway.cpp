#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d1,q;
long long w[505],k,x,y;
long long a[505],v[505];
long long d[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	cin>>c>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>v[j];
		}
		for(int j=1;j<=k;j++){
			for(int z=j+1;z<=k;z++){
				//e[a[j]].push_back({a[z],v[j]+v[z]});
				//e[a[z]].push_back({a[j],v[j]+v[z]});
				d[a[j]][a[z]]=min(d[a[j]][a[z]],v[j]+v[z]);
				d[a[z]][a[j]]=min(d[a[z]][a[j]],v[j]+v[z]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<d[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
