#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long dp[2100000];
long long dp2[2100000];
long long nxt[2100000];
long long x[2100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); 
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		memset(dp2,0,sizeof dp);
		memset(nxt,0,sizeof nxt);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i]=1;
		}
		x[0]=-3e18;
		x[0]-=7;
		x[n+1]=3e18;
		x[n+1]+=7;
		for(int i=1,k=0;i<=n;i++){
//			cout<<i;
			while(x[k+1]-x[i]<=d){
				nxt[++k]=i;
			}
		}
		nxt[n+1]=n+1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=nxt[nxt[i]];j<nxt[nxt[i]+1];j++){
				dp[i]+=dp[j];
				dp2[i]+=dp2[j];
			}
			for(int j=nxt[nxt[i]+1];j<nxt[min((long long)i,nxt[i]+2)];j++){
				dp2[i]+=dp[j];
			}
//			for(int j=nxt[i];j<i;j++){
//				dp2[i]+=dp2[j];
//			}
			ans+=dp2[i];
		}
//		for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=n;i++)cout<<dp2[i]<<" ";
//		cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
