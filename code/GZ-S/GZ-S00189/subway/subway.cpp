//GZ-S00189 ³Âè÷Ðù
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20001],s[20001],a[20001][20001],y5,x,y,vis[20001],ans=21000000,flag[20001];
int dfs(int a1,int dp){
	if(a1==y){
		ans=min(ans,dp);
		return 0;
	}
	else{
		vis[a1]=1;
		for(int i=1;i<=m&&a[a1][i]!=0;i++){
			if(vis[i]==0){
				vis[i]=0;
				return dfs(a[a1][i],dp+1);
				vis[i]=0;
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int g;
		cin>>g;
		for(int j=1;j<=g/2;j++){
			cin>>s[j]>>y5;
			for(int k=1;k<j;k++){
				a[s[j]][flag[j]]=s[j-k];
				a[s[j-k]][flag[j]]=s[j];
				flag[j]++;
			}
		}
		while(q--){
			cin>>x>>y;
			dfs(x,1);
			cout<<y5*(ans+1)+w[x]+w[y]<<endl;
		}
		
	}
	return 0;
}
