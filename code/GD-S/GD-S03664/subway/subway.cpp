#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],k[505],t[505][505],a[505][505],dis[505][505],g[505][505];
void d(){
	
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dis[i][j]=0;
			g[i][j]=i;
		}
	}
	while(q--){
		int xr,yr,sum;
		cin>>xr>>yr;
		if(g[xr][yr]){
			sum+=w[xr]+w[yr]+t[g[xr][yr]][xr]+t[g[xr][yr]][yr];
			cout<<sum;
			continue;
		}
		
	}
	return 0;
}
