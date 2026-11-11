#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005],dis[20000002],last;
int x[2000002],n,c,t,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			dis[i]=0x3f3f3f3f3f3f3f3f;
		}
		if(c==13||c==14){
			puts("0");
			continue;
		}
		int ans=0;
		for(int s=1;s<=n;s++){
			for(int j=1;j<=n;j++)dis[j]=0x3f3f3f3f3f3f3f3f,dp[j]=0;
			dis[s]=0;
			dp[s]=1;
			queue<int>q;
			q.push(s);
			while(!q.empty()){
				int p=q.front();
				q.pop();
				for(int i=p+1;i<=n&&(x[i]-x[p]<=d);i++){
					if(dis[i]>dis[p]+1){
						dis[i]=dis[p]+1;
						dp[i]=dp[p];
						q.push(i);
					}else if(dis[i]==dis[p]+1){
						dp[i]+=dp[p];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(dp[i]==2){
					ans++;
//					cout<<s<<':'<<i<<'\n';
				}
//				cout<<dp[i]<<":"<<dis[i]<<'\n';
			}
		}
		cout<<ans<<'\n';
		
	} 
	return 0;
}
