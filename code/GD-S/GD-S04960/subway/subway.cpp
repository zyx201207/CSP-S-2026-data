#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
long long w[1000000];
long long k[105],a[105][500005],t[105][500005],dist[105][105];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=10000000000000;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			for(int z=1;z<j;z++){
				dist[a[i][z]][a[i][j]]=min(dist[a[i][z]][a[i][j]],t[i][a[i][z]]+t[i][a[i][j]]);
				dist[a[i][j]][a[i][z]]=dist[a[i][z]][a[i][j]];
				
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	while(p!=0){
		p--;
		int xr,yr;
		cin>>xr>>yr;
		int ans=w[xr]+dist[xr][yr]+w[yr];
		cout<<ans<<endl;
	}
	return 0;
} 
