#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[2005];
long long a[2005];
long long t[2005];
long long g[2005][2005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			g[i][j]=999999999;
		}
		g[i][i]=0;
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				g[a[i]][a[j]]=t[i]+t[j];
				g[a[j]][a[i]]=t[i]+t[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
			}
		}
	}
	for(long long i=1,a,b;i<=q;i++){
		cin>>a>>b;
		cout<<g[a][b]+w[a]+w[b]<<endl;
	}
	return 0;
}
