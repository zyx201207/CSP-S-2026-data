#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+5;
int x[N],c,t,n,d,dp[5005][5005];
void dfs(int idx,int cnt){
	if(idx>=n) return;
	for(int i=1;i<=d;i++){
	if(cnt<=n/d){
		dp[idx][idx+d]+=1;
		dfs(idx+d,cnt+1);
	}
	}
	
}
signed main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=2;i<=n-1;i++){
			if(x[i]-x[i-1]!=x[i+1]-x[i]){
				f=0;
				break;
			}
		}
		memset(dp,0,sizeof(dp));
		int cnt=0;
		dfs(1,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
