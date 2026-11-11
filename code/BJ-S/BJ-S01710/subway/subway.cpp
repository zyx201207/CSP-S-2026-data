#include<bits/stdc++.h>
using namespace std;
int a[505][50005];
long long w[50005],t[505][50005];
long long di[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			di[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			di[a[i][j-1]][a[i][j]]=t[i][j]+t[i][j-1];
			di[a[i][j]][a[i][j-1]]=t[i][j]+t[i][j-1];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(di[i][j]>di[i][k]+di[k][j]){
					di[i][j]=di[i][k]+di[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<di[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
