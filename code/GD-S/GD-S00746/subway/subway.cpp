#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],a[n+1][d+1],t[n+1][d+1],k[n+1],l[m+1][m+1],z[m+1];
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			l[i][j]=l[j][i]=500001;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int y=1;y<j;y++){
				if(y!=1){
					l[a[i][y-1]][a[i][y]]=l[a[i][y]][a[i][y-1]]=min(l[a[i][y]][a[i][y-1]],t[i][y]+t[i][y-1]);
				}
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				l[i][k]=l[j][k]=min(l[i][k],l[i][j]+l[j][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<l[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
