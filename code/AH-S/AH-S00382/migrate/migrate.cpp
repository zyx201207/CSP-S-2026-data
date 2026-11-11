#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[2000010],ans,js,dp[2000010];
void dfs(int x,int y,int cnt,long long tmp,int dq){
	if(dq==y){
		if(tmp==cnt){
			js++;
			return;
		}
	}
	if(js>2) return;
	for(int i=dq;i<=y;i++){
		if(a[i]-a[dq]<=d){
			dfs(x,y,cnt+1,tmp,i);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[1]<=d){
				dp[i]=1;
			}else if(a[i]-a[i-1]<=d){
				dp[i]=min(dp[i-1]+1,dp[i-2]+1);
			}else{
				dp[i]=-1;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])<=d){
					continue;
				}//only1
					if((a[j]-a[i])/d==1&&(a[j]-a[i])%d<d&&(a[j]-a[i])%d>0){
						
						ans++;
					}
					continue;
				/*
				if(dp[j]==-1){
					continue;
				}//wu
				if(dp[i]==-1) dp[i]=0;
				long long tmpp=dp[j]-dp[i];
				if(tmpp<=0) tmpp=1;
				js=0;
				dfs(i,j,0,tmpp,i);
				if(js==2){
					ans++;
				}*/
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
