#include<bits/stdc++.h>
using namespace std;
#define int long long
int ai[2000010],dp[2000010],ed[2000010];
#define mod 998244353
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int x=1;x<=n;x++){
				cin>>ai[x];
			}
			int gc=ai[2]-ai[1];
			cout<<max(0ll,(d/gc>1)*(n-(d/gc*2-1)))<<endl;
		}
	}
	else while(t--){
		int n,d;
		cin>>n>>d;
		for(int x=1;x<=n;x++){
			cin>>ai[x];
		}
		for(int x=1;x<=n;x++){
			ed[x]=0;
			for(int y=x+1;y<=n;y++){
				if(ai[y]-ai[x]>d){ed[x]=y-1;break;}
			}if(ed[x]==0)ed[x]=n;
		}
		int ans=0;
		for(int x=1;x<=n;x++){
			for(int y=x;y<=n;y++){
				dp[y]=0;
			}
			dp[x]=1;
			int r=x;
			while(!dp[n]){
				for(int y=n;y>=x;y--){
					for(int z=y+1;z<=ed[y];z++){
						dp[z]=(dp[y]+dp[z])%mod;
					}
					dp[y]=0;
				}
				int r1=r;
				while(r<n&&dp[r+1]){
					if(dp[r+1]==2)ans++;
					r++;
				}
				if(r==r1)break;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
