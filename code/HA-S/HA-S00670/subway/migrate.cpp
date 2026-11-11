#include<bits/stdc++.h>
using namespace std;
int sum[10005],a[10005][20005],vis[10005];
void dfs(long long d,int i,int j){
	if(a[i][j+1]==0){
		sum[i]++;
		return ;
	}
	if(vis[j]==1){
		return ;
	}
	vis[j]=1;
	if(a[i][j+1]-a[i][j]<=d&&a[i][j+1]!=0){
		dfs(d,i,j+1);
	}
	if(a[i][j+2]-a[i][j]<=d&&a[i][j+2]!=0){
		dfs(d,i,j+2);
	}
	if(a[i][j+3]-a[i][j]<=d&&a[i][j+3]!=0){
		dfs(d,i,j+3);
	}
	if(a[i][j+4]-a[i][j]<=d&&a[i][j+4]!=0){
		dfs(d,i,j+4);
	}
	if(a[i][j+5]-a[i][j]<=d&&a[i][j+5]!=0){
		dfs(d,i,j+5);
	}
	if(a[i][j+6]-a[i][j]<=d&&a[i][j+6]!=0){
		dfs(d,i,j+6);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		long long d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		dfs(d,i,1);
		cout<<sum[i]%2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
