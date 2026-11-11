#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			int nd=d/(a[2]-a[1]);
			if(nd<=1){
				cout<<"0\n";
				continue;
			}
			int ans=0;
			for(int i=1;i+nd*2-1<=n;i++) ans++;
			cout<<ans<<'\n';
			continue;
		}
		else{
			int num=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int ans=LLONG_MAX;
					vector<int> vis(n+1,0);
					auto dfs=[&](auto &&self,int nw,int sum)->void {
						if(nw==j){
							ans=min(ans,sum);
							vis[sum]++;
							return ;
						}
						for(int k=nw+1;k<=j;k++){
							if(a[k]-a[nw]>d) break;
							self(self,k,sum+1);
						}
					};
					dfs(dfs,i,0);
					if(vis[ans]==2) num++;
				}
			}
			cout<<num<<'\n';	
		}
	}
	return 0;
}
