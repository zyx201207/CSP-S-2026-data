#include<bits/stdc++.h>
#define int long long 
#define INF 1e14
using namespace std;
int w[500009];
int zt1[500009][29],zt2[500009][29],t[500009];
int a[509][509];
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q,k,hyw,ywh;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>hyw>>ywh;
			t[hyw]++;
			zt1[hyw][t[hyw]]=i;
			zt2[hyw][t[hyw]]=ywh;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i)a[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t[i];j++){
			for(int k=1;k<=t[i];k++){
				a[zt1[i][j]][zt1[i][k]]=min(a[zt1[i][j]][zt1[i][k]],zt2[i][j]+zt2[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int mn=1e18;
		for(int j=1;j<=t[x];j++){
			for(int k=1;k<=t[y];k++){
				mn=min(mn,w[x]+w[y]+zt2[x][j]+zt2[y][k]+a[zt1[x][j]][zt1[y][k]]);
				//cout<<zt1[x][j]<<" "<<zt1[y][k]<<" "<<zt2[x][j]<<" "<<zt2[y][k]<<" *\n";
			}
		}
		cout<<mn<<"\n";
	}
	return 0;
}
