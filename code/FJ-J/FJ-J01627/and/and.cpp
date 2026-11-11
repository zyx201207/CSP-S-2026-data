#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+15;
long long a[N],dp[2]; //cong 0-n ,m=j(gun dong shu zu) shi an wei yu de zui da zhi
bool st[N];
int dres;
void dfs(int u,int cnt,int res){
	if(cnt==m){
		dres=max(dres,res);
		return;
	}
	if(u==n+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=1;
		dfs(u+1,cnt+1,res&a[i]);
		st[i]=0;
		dfs(u+1,cnt,res);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=14){
		dfs(1,0,-1);
		cout<<dres;
		return 0;
	}
	dp[0]=-1;
	for(int j=1;j<=m;j++){
		int mi=0;
		dp[j%2]=0;
		for(int i=1;i<=n;i++){
			if(st[i]) continue;
			if(dp[j%2]<(dp[(j-1)%2]&a[i])){
				dp[j%2]=(dp[(j-1)%2]&a[i]);
				//cout<<"dp["<<j<<"%2("<<j%2<<")]:"<<dp[j%2]<<"\n";
				mi=i;
			}
		}
		st[mi]=1;
	}
	cout<<dp[m%2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
