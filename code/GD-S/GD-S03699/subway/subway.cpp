#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1005],a[1005][1005],t[1005][1005],b[1005][1005],di[1005][1005],k,x,y;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
		
			cin>>a[i][j];
			b[a[i][j]][a[i][j-1]]=1;
			b[a[i][j-1]][a[i][j]]=1;
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(b[i][k]==1 && b[k][j]==1){
					di[i][j]=min(di[i][j],t[i][k]+t[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<di[x][y]+w[x]+w[y];
	}
	return 0;
}
