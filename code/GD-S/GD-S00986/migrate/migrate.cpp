#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int type,t,n,d,a[N],to[N],f[N],g[N],dp[N][3],vis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>type>>t;
	while(t--){
		cin >>n>>d;
		for(int i=1;i<=n;i++)cin >>a[i];
		for(int i=1;i<=n;i++){
			to[i]=f[i]=g[i]=vis[i]=0;
			dp[i][0]=dp[i][1]=dp[i][2]=0;
		}
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<=r){
				int mid=l+r>>1;
				if(a[mid]-a[i]<=d)to[i]=mid,l=mid+1;
				else r=mid-1;
			}
		}
		for(int i=1;i<=n;i++)if(to[i]>i){
			if(to[i]==i+1)f[i]=to[to[i]]-to[i],g[i]=0;
			else if(to[i]==i+2){
				f[i]=to[to[i]]-to[to[i]-1];
				g[i]=to[to[i]-1]-to[i];
			}else{
				f[i]=to[to[i]]-to[to[i]-1];
				g[i]=to[to[i]-1]-to[to[i]-2];
			}
		}
//		for(int i=1;i<=n;i++)cout <<f[i]<<" "<<g[i]<<"\n";
		for(int i=1;i<=n;i++)if(to[i]>i){
			if(to[i]==i+1)vis[i]=0;
			else if(to[i]==i+2){
				if(a[to[to[i]]]-a[to[i]-1]<=d)vis[i]=1;
				else vis[i]=0;
			}else{
				if(a[to[to[i]]]-a[to[i]-1]<=d){
					if(a[to[to[i]]]-a[to[i]-2]<=d)vis[i]=2;
					else vis[i]=1;
				}else vis[i]=0;
			}
		}
//		for(int i=1;i<=n;i++)cout <<vis[i]<<" ";cout <<"\n";
		for(int i=1;i<=n;i++)dp[i][0]=f[i],dp[i][1]=g[i];
		for(int i=n;i>=1;i--)if(to[i]>i&&vis[i]!=2){
			if(vis[i]==1)dp[i][1]+=dp[to[i]][0];
			else{
				dp[i][0]+=dp[to[i]][0],dp[i][2]+=dp[to[i]][2];
				if(a[to[to[i]]-1]-a[to[i]-1]>d)dp[i][2]+=dp[to[i]][1];
			}
		}
//		for(int i=1;i<=n;i++)cout <<dp[i][1]<<" ";cout <<"\n";
		int ans=0;
		for(int i=1;i<=n;i++)ans+=dp[i][1]+dp[i][2];
		cout <<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
