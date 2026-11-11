#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[200055],k[200055],vis[1050][1050];
int a[1050][1050],t[1050][1050];
int dp[1050][1050];
int ss=0;
int dfs(int st,int en,int xx,int yy){
	int ans=1e9;
	if(st==en){
		return 0;
	}
	int flag=0;
	for(int e=yy;e<=k[xx];e++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[xx][e]==a[i][j]&&vis[i][j]==0){
					vis[i][j]=1;
					flag=1;
					ans=min(ans,dfs(a[i][j],en,i,j));
				}
			}
		}
	}
	ans+=w[st]+t[st][xx];
	if(flag==1)return ans;
 	return 1e9;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[i][j]=0;
		}
		int xr,yr,xxx,yyy;
		cin>>xr>>yr;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==xr){
					xxx=i;
					yyy=j;
					break;
				}
			}
		}
		vis[xxx][yyy]=1;
		cout<<dfs(xr,yr,xxx,yyy)+w[xr]+t[xr][xxx]<<'\n';
	}
	return 0;
} 
