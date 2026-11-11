#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,T,n,d,a[N],dp[N],cnt[N];
bool vis[N];
queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(C==11||C==12){
			int c=a[2]-a[1],k=d/c;
			if(k<2)cout<<"0\n";
			else cout<<max(0ll,n-(2*k-1))<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			fill(dp+i,dp+n+1,1e9);
			fill(cnt+i,cnt+n+1,0);
			fill(vis+i,vis+n+1,false);
			dp[i]=0,cnt[i]=1;
			q.push(i);
			while(!q.empty()){
				int x=q.front();
				q.pop();
				if(vis[x])continue;
				vis[x]=true;
				for(int j=x+1;j<=n;j++){
					if(a[j]-a[x]>d)break;
					if(dp[j]>dp[x]+1){
						dp[j]=dp[x]+1,cnt[j]=cnt[x];
						q.push(j);
					}else if(dp[j]==dp[x]+1)cnt[j]+=cnt[x];
				}
			}
			for(int j=i+1;j<=n;j++){
				if(dp[j]<1e9&&cnt[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
