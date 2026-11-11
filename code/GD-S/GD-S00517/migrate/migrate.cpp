#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],f[2000005],dis[2000005],g[2000005];
signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		dis[0]=1;
		for(int i=1;i<=n;i++){
			dis[i]=dis[i-1];
			while(a[dis[i]]-a[i]<=d&&dis[i]<=n)dis[i]++;
			dis[i]--;
		}
		for(int i=n;i>=1;i--){
			if(dis[i]>dis[i-1]&&i!=dis[i])f[i]=f[dis[i]]+1;
		}
		for(int i=1;i<=n;i++){
			if(dis[i]>dis[i-1]&&i!=dis[i])g[dis[i]]=g[i]+1;
		}
		int ans=0;
		for(int i=2;i<=n;i++){
			ans+=g[i]*(min(dis[i-1]-i,dis[i-1]-dis[i-2]));
			if(dis[i]==dis[i-1]&&dis[i]>dis[i-2])ans+=g[i]*f[dis[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
