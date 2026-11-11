#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d;
long long a[2000010];
long long f[5010][5010],mi[5010][5010];//f->cishu  mi->lenth
long long ans;
bool vis[5010];
void dfs(int x){
	vis[x]=1;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			mi[x][i]=1;
			f[x][i]=1;
			if(!vis[i])dfs(i);
			for(int j=i+1;j<=n;j++){
				if(mi[x][i]!=0x3f3f3f3f3f3f3f3f&&mi[i][j]!=0x3f3f3f3f3f3f3f3f&&mi[x][j]==mi[x][i]+mi[i][j]){
					f[x][j]++;
				}
				if(mi[x][i]!=0x3f3f3f3f3f3f3f3f&&mi[i][j]!=0x3f3f3f3f3f3f3f3f&&mi[x][j]>mi[x][i]+mi[i][j]){
					mi[x][j]=mi[x][i]+mi[i][j];
					f[x][j]=1;
				}
					
			}
		
		}
	}
//	cout<<x<<":";
	for(int i=x+1;i<=n;i++){
//		cout<<f[x][i]<<' ';
		if(f[x][i]==2){
			ans++;
		}
	}
//	cout<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mi[i][j]=0x3f3f3f3f3f3f3f3f;
				f[i][j]=0;
				if(i==j){
					mi[i][j]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
