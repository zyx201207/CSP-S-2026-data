#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int k[502];
int a[502][1003],t[502][1003];
int f[1003][1003];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=0;j<k[i];j++)
			for(int l=0;l<k[i];l++){
				f[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
				f[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
			}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]==0){
					f[i][j]=f[i][l]+f[j][l];
					f[j][i]=f[i][l]+f[j][l];
				}
				f[i][j]=min(f[i][l]+f[j][l],f[i][j]);
				f[j][i]=min(f[i][l]+f[j][l],f[i][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

