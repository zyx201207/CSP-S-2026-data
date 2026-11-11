#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
pair<int,int> dp[2000005];
bool check(int u,int v){
	dp[u]={1,0};
	for(int i=u+1;i<=v;i++){
		dp[i]={0,0};
		int mink=v-u,dist=x[v]-x[u];
		for(int j=i-1;j>=u;j--){
			if(x[i]-x[j]>d)break;
			if(mink>dp[j].second){
				mink=dp[j].second;
				dist=dp[j].first;
			}else if(mink==dp[j].second){
				dist+=dp[j].first;
			}
		}
		dp[i]={dist,mink+1};
	}return dp[v].first==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(check(j,i))ans++;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
