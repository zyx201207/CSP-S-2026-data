#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010],vis[510][510],s,ans=1e18;
void dfs(int k,int n,int d,int an,int x){
	if(k==n){
		if(an<ans)vis[x][n]=1,ans=an;
		else if(an==ans)vis[x][n]++;
	}
	if(k>n||an>ans)return ;
	for(int i=k+1;i<=n;i++){
		if(a[i]-a[k]<=d)dfs(i,n,d,an+1,x);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin >>t>>c;
	while(c--){
		int n,d;
		s=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin >>n>>d;
		for(int i=1;i<=n;i++)cin >>a[i];
		if(n>300){
			for(int i=4;i<=n;i+=2)s+=n-i+1;
			cout <<s<<endl;
		}else{
			int t=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					ans=1e18,dfs(i,j,d,0,i);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(vis[i][j]==2)t++;
				}
			}
			cout <<t<<endl;
		}
	}
	return 0;
}
