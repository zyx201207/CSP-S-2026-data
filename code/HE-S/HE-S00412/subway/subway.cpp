#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,xx,yy;
int z[500005],x[500005],t[500005];
int w[15005][15005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>z[i];
		w[3*i][3*i+1]=z[i];
		w[3*i+1][3*i]=z[i];
	}
	cin>>k;
	for(int i=1;i<=k;++i){
		cin>>x[i]>>t[i];
		w[3*i+2][3*i+1]=t[i];
		w[3*i+1][3*i+2]=t[i];
		
	}
	for(int k=1;k<=3*n;++k){
		for(int i=1;i<=3*n;++i){
			for(int j=1;j<=3*n;++j){
				w[i][j]=max(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		cin>>xx>>yy;
		cout<<w[3*xx+1][3*yy+1]<<endl;
		
	}
}

