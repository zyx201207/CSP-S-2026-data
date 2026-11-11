#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
//1 0
//2 1
//11 2
//21 3
//22 4
//111 5
using namespace std;
int c,t,n,d,ans,a[maxn],to[maxn],dp[maxn][6];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) cin>>a[i],dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=dp[i][4]=dp[i][5]=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]-a[i]<=d) j++;
			to[i]=j-1;
		}
		for(int i=n;i>=1;i--){
			if(to[i]==i) continue;
			if(to[i]==i+1) dp[i][0]=dp[to[i]][0];//1-1
			else if(to[i]==i+2) dp[i][0]=dp[to[i]][2];//1-11
			else dp[i][0]=dp[to[i]][5];//1-111
			if(to[i]==i+1) dp[i][1]=dp[to[i]][1]+to[i]-i;//2-2
			else dp[i][1]=dp[to[i]][4]+to[i]-i;//2-22
			if(i==1) continue;
			if(to[i-1]<=i){
				dp[i][2]=dp[i][3]=dp[i][5]=dp[i][0],dp[i][4]=dp[i][1];
				continue;
			}
			if(to[i]==i+1) dp[i][2]=dp[to[i]][1]+to[i-1]-i;//11-2
			else if(to[i]==i+2){
				if(to[i-1]==to[i]-1) dp[i][2]=dp[to[i]][3]+to[i-1]-i;//11-21
				else dp[i][2]=dp[to[i]][4]+to[i-1]-i;//11-22
			}
			else{
				if(to[i-1]<=to[i]-2) dp[i][2]=dp[to[i]][5]+to[i-1]-i;//11-111
				else if(to[i-1]==to[i]-1) dp[i][2]=dp[to[i]][3]+to[i-1]-i;//11-21
				else if(to[i-1]==to[i]) dp[i][2]=dp[to[i]][4]+to[i-1]-i;//11-22
			}
			if(to[i]==i+1) dp[i][3]=0;
			else if(to[i]==i+2){
				if(to[i-1]==to[i]-1) dp[i][3]=dp[to[i]][3];//21-21
			}
			else{
				if(to[i-1]<=to[i]-2) dp[i][3]=dp[to[i]][5];//21-111
				else if(to[i-1]==to[i]-1) dp[i][3]=dp[to[i]][3];//21-21
			}
			if(to[i-1]!=to[i]) dp[i][4]=dp[to[i]][4]+to[i]-to[i-1];//12-12
			if(i==2) continue;
			if(to[i-2]<=i){
				dp[i][5]=dp[i][2];
				continue;
			}
			if(to[i]==i+1) dp[i][5]=0;
			else if(to[i]==i+2){
				if(to[i-2]==to[i]-1){
					if(to[i-1]==to[i]-1) dp[i][5]=dp[to[i]][3]+to[i-1]-to[i-2];//111-21
					else dp[i][5]=dp[to[i]][4]+to[i-1]-to[i-2];//111-22
				}
			}
			else{
				if(to[i-2]<=to[i]-2){
					if(to[i-1]<=to[i]-2) dp[i][5]=dp[to[i]][5]+to[i-1]-to[i-2];//111-111
					else if(to[i-1]==to[i]-1) dp[i][5]=dp[to[i]][3]+to[i-1]-to[i-2];//111-21
					else dp[i][5]=dp[to[i]][4]+to[i-1]-to[i-2];//111-22
				}
				else if(to[i-2]==to[i]-1){
					if(to[i-1]==to[i]-1) dp[i][5]=dp[to[i]][3]+to[i-1]-to[i-2];//111-21
					else dp[i][5]=dp[to[i]][4]+to[i-1]-to[i-2];//111-22
				}
			}
		}
		for(int i=1;i<=n;i++) ans+=dp[i][0];
		cout<<ans<<"\n";
	}
	cout.flush();
}
