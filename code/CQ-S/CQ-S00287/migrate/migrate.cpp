#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2100005],dp[2100005],cnt[2100005],vis[2100005],du[2100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int test,t;
	cin>>test>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1;
		for(int i=1;i<=n;i++){
			while(a[l+1]-a[i]<=m&&l+1<=m){
				l++;
			}
			vis[i]=l;
		}
		if(test==12||test==11){
			if(vis[1]<=2){
				cout<<0<<endl;
				continue;
			}
			int now=vis[1]-1;
			now=now*2-1;
			cout<<max(n-now,(int)(0))<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)dp[j]=0,cnt[j]=0;
			dp[i]=1,cnt[i]=1;
			int l=i,now=1;
			for(int j=i+1;j<=n;j++){
				while(a[j]-a[l]>m){
					now-=cnt[l];
					l++;
				}
				int minn=1e18,cp=0;
				for(int k=l;k<j;k++){
					if(dp[k]<minn)minn=dp[k],cp=cnt[k];
					else if(dp[k]==minn)cp+=cnt[k];
				}
				cnt[j]=cp;
				dp[j]=minn+1;
				//cout<<dp[j]<<cnt[j]<<" ";
				if(cnt[j]==2)ans++;
			}
		//	cout<<ans<<endl; 
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
