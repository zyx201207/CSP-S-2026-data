#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[500005],a[500005];
int f[405][405];
void build(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i!=j&&j!=k)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[a[j]];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(l!=j)f[a[l]][a[j]]=min(f[a[l]][a[j]],t[a[l]]+t[a[j]]);
			}
		}
	}
	build();
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<f[s][e]+w[s]+w[e]<<'\n';
	}
	return 0;
}
