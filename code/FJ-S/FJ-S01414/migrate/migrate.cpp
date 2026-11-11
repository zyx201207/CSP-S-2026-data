#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f; 
int c,t,x[N],dis[N],cnt[N],n,d; 
void dfs(int now,int sum){
	if(now>=n){
		return;
	}
	int p=upper_bound(x+1,x+n+1,x[now]+d)-x;
	if(p<1) return;
	if(p>n) p=n+1;
	p--;
	for(int i=now+1;i<=p;i++){
		if(sum+1==dis[i]){
			cnt[i]++;
		}else if(sum+1<dis[i]){
			cnt[i]=1;
			dis[i]=sum+1;
		}
		dfs(i,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[j]=INF;
				cnt[j]=0;
			}
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
