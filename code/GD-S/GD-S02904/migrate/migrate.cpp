#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+10;
int pre[N],x[N],dp[2][N],net[N];
int CNT,T,n,d,answer;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>CNT>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<=n;++i){
			pre[i]=i;
			int L=1,R=i-1,ans=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(x[i]-x[mid]<=d){
					ans=mid;R=mid-1;
				}else L=mid+1;
			}pre[i]=ans;
		}for(int i=1;i<=n;++i){
			net[i]=i;
			int L=i+1,R=n,ans=0;
			while(L<=R){
				int mid=(L+R)>>1;
				if(x[mid]-x[i]<=d){
					ans=mid;L=mid+1;
				}else R=mid-1;
			}net[i]=ans;
		}dp[0][0]=1;dp[1][0]=0;answer=0;
		for(int i=1;i<=n;++i){
			dp[0][i]+=dp[0][pre[i]];
			dp[1][i]+=dp[1][pre[i]];
			if(pre[pre[i]+1]<pre[i]&&(net[pre[pre[i]+1]]==(pre[i]+1))){
				dp[1][i]+=dp[0][pre[pre[i]+1]];
			}
			cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
			answer+=dp[1][i];
		}cout<<answer<<"\n";
		for(int i=0;i<=n;++i){
			dp[0][i]=dp[1][i]=0;
		}
	}
	return 0;
}
