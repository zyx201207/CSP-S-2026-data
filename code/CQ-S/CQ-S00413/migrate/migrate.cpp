#include<bits/stdc++.h>
#define int long long
#define N 2000006
using namespace std; 
int c,t,n,d,x[N],y[N],xy,v[N],dp[N][2],ans;
unordered_map<int,int> mp[N];
void dfs(int qd,int zd,int cnt,int sum,int b){
	if(qd==zd){
		if(b==1) cnt++;
		cnt++; 
		if(b==1&&sum==y[qd-1]){
			return ;
		} 
		mp[zd][cnt]++;
		dp[zd][0]=min(dp[zd][0],cnt);
		return ;
	}if(b==1){
		if(sum+y[qd]<=d){
			dfs(qd+1,zd,cnt,sum+y[qd],1);
		}
		if(sum>y[qd-1]) dfs(qd+1,zd,cnt+2,0,0);
	}else{
		dfs(qd+1,zd,cnt,y[qd],1);
		dfs(qd+1,zd,cnt+1,0,0);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=xy+1;i<=xy+n;i++) cin>>x[i];
		for(int i=xy+2;i<=xy+n;i++) y[i]=x[i]-x[i-1];
		for(int i=xy+1;i<xy+n;i++){
			for(int j=i+1;j<=xy+n;j++){
				for(int k=i;k<=j;k++) dp[k][0]=dp[k][1]=1e17,mp[k].clear();
				dfs(i,j,0,0,0),ans+=(mp[j][dp[j][0]]==2);
//				if(mp[j][dp[j][0]]==2) cout<<i<<" "<<j<<"\n";
			}
		}
		cout<<ans+1<<"\n";
	}
	
	return 0;
}
