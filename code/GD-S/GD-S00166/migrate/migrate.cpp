#include<bits/stdc++.h>
using namespace std;
int n,kk,e,m,ans,a[10001][10001],u[10001][10001],b[10001],f[10001][10001];
void made(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=(b[j]-b[i],b[i]-b[j]);
			a[j][i]=a[i][j];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>kk>>e;
	while(e--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		memset(u,0,sizeof(u));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	made();
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][k]<=m&&a[k][j]<=m){
					if(f[i][j]==f[i][k]+f[k][j])u[i][j]++;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(u[i][j]==2)ans++;
		}
	}cout<<ans/2<<endl;
}
	return 0;
}
