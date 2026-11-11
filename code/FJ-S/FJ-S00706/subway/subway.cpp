#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],k[505],a[505][50005],t[505][50005],h[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=5001;i++){
		for(int j=i+1;j<=5001;j++){
			h[i][j]=h[j][i]=1e10;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			for(int jj=1;jj<j;jj++){
				h[a[i][j]][a[i][jj]]=h[a[i][jj]][a[i][j]]=min(h[a[i][j]][a[i][jj]],t[i][j]+t[i][jj]);
			}
		}
	}
	for(int jj=1;jj<=m;jj++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				h[i][j]=h[j][i]=min(h[i][j],h[i][jj]+h[jj][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<h[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
