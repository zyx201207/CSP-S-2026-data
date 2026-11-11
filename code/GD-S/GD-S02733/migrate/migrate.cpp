#include<iostream>
#define int long long
#define N 2000010
using namespace std;
int c,t,n,d,ans,a[N],cnt[N],dp[N];
int q[N],head,tail;
bool vis[N];
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			head=1,tail=1;dp[1]=0;cnt[1]=1;q[tail]=1;
			for(int j=2;j<=n;j++){
				cnt[j]=0;
				while(head<=tail&&a[j]-a[q[head]]>d)head++;
				for(int k=head;k<=tail;k++){
					if(k==head||dp[q[k]]==dp[q[k-1]]){
						cnt[j]+=cnt[q[k]];
						if(cnt[j]>=3)break;
					}
					else break;
				}
				if(cnt[j]==2){
					//ans++;
					vis[j]=true;
				}
				//cout<<cnt[j]<<" ";
				dp[j]=dp[q[head]]+1;
				while(head<=tail&&dp[j]<dp[q[tail]])tail--;
				q[++tail]=j;
			}
			for(int i=2;i<=n;i++){
				if(vis[i]){
					vis[i]=false;
					ans+=n-i+1;
				}
			}
			cout<<ans<<'\n';ans=0;
		}
		else{
			for(int i=1;i<=n;i++){
				head=1,tail=1;dp[i]=0;cnt[i]=1;q[tail]=i;
				for(int j=i+1;j<=n;j++){
					cnt[j]=0;
					while(head<=tail&&a[j]-a[q[head]]>d)head++;
					for(int k=head;k<=tail;k++){
						if(k==head||dp[q[k]]==dp[q[k-1]]){
							cnt[j]+=cnt[q[k]];
							if(cnt[j]>=3)break;
						}
						else break;
					}
					if(cnt[j]==2){
						ans++;
					}
					//cout<<cnt[j]<<" ";
					dp[j]=dp[q[head]]+1;
					while(head<=tail&&dp[j]<dp[q[tail]])tail--;
					q[++tail]=j;
				}
			}
			cout<<ans<<'\n';ans=0;
		}
	}
	return 0;
}
