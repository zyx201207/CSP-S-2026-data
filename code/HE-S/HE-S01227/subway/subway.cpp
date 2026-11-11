#include<bits/stdc++.h>
using namespace std;
int w[15],k[5],a[5][15],t[5][15];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(n==1){
		int x,y,xx,yy;
		while(q--){
			cin>>x>>y;
			for(int i=1;i<=k[1];i++){
				if(a[1][i]==x){
					xx=i;
				}if(a[1][i]==y){
					yy=i;
				}
			}
			cout<<w[x]+w[y]+t[1][xx]+t[1][yy]<<endl;
		}
	}
	return 0;
}
