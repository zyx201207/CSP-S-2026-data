#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--){
		int n,d,x,p,ans=0;
		cin>>n>>d;
		unordered_map<int,int> dp;
		cin>>p;
		dp[p]=1;
		for(int i=2;i<=n;i++){
			cin>>x;
			int cnt=0;
			for(int j=1;j<=d;j++){
				if(x-j<=0) break;
				if(!dp.count(x-j)) continue;
				if(dp[x]==dp[x-j]+1) cnt++;
				dp[x]=min(dp[x-j]+1,dp[x]);
			}
			if(cnt==1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
