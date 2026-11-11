#include<bits/stdc++.h>
using namespace std;
int qwe,t,n,m;
long long a[2000010],g[5010][5010],ans[5010][5010],cnt;
int b[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>qwe>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++){
				g[i][j]=1e7;
				ans[i][j]=1;
				if(i==j)g[i][j]=0;
			}
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]>m)break;
				g[i][j]=g[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				for(int i=1;i<=n;i++){
					if(j==k||j==i||i==k)qwe=qwe;
					else if(g[i][j]>g[i][k]+g[k][j]){
						g[i][j]=g[i][k]+g[k][j];
						ans[i][j]=1;
					}
					else if(g[i][j]==g[i][k]+g[k][j]){
						ans[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans[i][j]==2&&b[i][j]==0){
					//b[i][j]=b[j][i]=1;
					cnt++;
				}
			}
		}/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cout<<ans[i][j]<<" ";
			cout<<endl; 
		}*/
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
