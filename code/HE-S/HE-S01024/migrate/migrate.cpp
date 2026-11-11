#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[2000010];
int dp[5001][5001];
bool vis[5001][5001];
int d[5001][5001];
int f[5001][5001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
	while(t--){
		cin>>n>>m;
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(d,0x3f,sizeof(d));
        memset(f,0x3f,sizeof(f));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					f[i][j]=min(a[j]-a[i],f[i][j]);
					f[j][k]=min(a[k]-a[j],f[j][k]);
					if(a[k]-a[j]<=m&&a[j]-a[i]<=m&&a[k]-a[j]+a[j]-a[i]==d[i][k]&&f[i][j]==a[j]-a[i]&&f[j][k]==a[k]-a[j]){
						dp[i][k]++;
					}else{
						d[i][k]=f[i][j]+f[j][k];
						dp[i][k]=1;
					}
					if(f[i][j]<a[j]-a[i]||f[j][k]<a[k]-a[j]){
						for(int p=1;p<=n;p++){
							dp[p][k]=0;
						}
					}
					}
				}
			}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
			for(int j=k+1;j<=n;j++){
				if(dp[i][j]==2&&vis[i][j]==0){
					cnt++;
					vis[i][j]=1;
				}
		}
		} 
}
	cout<<cnt<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
