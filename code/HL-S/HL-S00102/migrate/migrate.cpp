#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int x[N];
int dis[N];
int q[N];
int dp[N];
int head,tail;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dis[i]=0;
			head=0,tail=0;
			q[++tail]=i;
			for(int j=i+1;j<=n;j++){
				dp[j]=0;
				while(head<tail&&x[j]-x[q[head+1]]>d)head++;
				if(head>=tail)dis[j]=3e18;
				else dis[j]=dis[q[head+1]]+1,q[++tail]=j;
			}
			dp[i]=1;
			head=0,tail=1;
			q[tail]=i;
			int sum=1;
			for(int j=i+1;j<=n;j++){
				while(head<tail&&dis[q[head+1]]+1<dis[j])head++,sum-=dp[q[head]];
				if(dis[j]==dis[j-1]){
//					cout<<j<<" nn\n";
					dp[j]=dp[j-1];
					while(head<tail&&x[j]-x[q[head+1]]>d)head++,dp[j]-=dp[q[head]],sum-=dp[q[head]];
					q[++tail]=j;
					sum+=dp[j];
				}
				else{
//					cout<<j<<' '<<head<<' '<<tail<<" mm\n";
					while(head<tail&&x[j]-x[q[head+1]]>d)head++,sum-=dp[q[head]];
					dp[j]=sum;
					q[++tail]=j;
					sum+=dp[j];
				}
			}
//			for(int j=i;j<=n;j++){
//				cout<<dp[j]<<' ';
//			}
//			cout<<'\n';
			for(int j=i+1;j<=n;j++){
				if(dp[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
// I love Skirk
//18:13:20 force finish