#include<bits/stdc++.h>
#define int long long
#define u_m unordered_map
using namespace std;
const int N=5e3+10,M=2e6+10;
int f[N],lst[M],x[M],c,t,n,d,g[N];
struct node{
	int lf,rt;
};
u_m <int,int> mp;
//init
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int l=n,r=n;l>=1;l--){
			while(x[r]-x[l]>d) r--;
			lst[l]=r;
		}
		if(c==11||c==12){
			int k=x[2]-x[1];
			int cnt=d/k;
			if(cnt==0||cnt==1){
				cout<<"0\n";
				continue;
			}
			for(int v=1;v<=n;v++){
				if(v>=2*cnt){
					ans++;
				}
			}
			cout<<ans<<'\n';
			continue; 
		}
		for(int v=2;v<=n;v++){
			mp.clear();
			for(int u=v-1;u>=1;u--) f[u]=-1,g[u]=0;
			f[v]=0,g[v]=0;
			for(int u=v-1;u>=1;u--){
				if(x[v]-x[u]<=d){
					f[u]=1,g[u]=1;
					continue;
				} 
				if(f[lst[u]]==-1) break;
				else{
					f[u]=f[lst[u]]+1;
				}
				mp[f[u]]=u;
			}
			for(int u=v-1;u>=1;u--){
				for(int k=min(lst[u],v);k>u;k--){
					if(f[k]==f[u]-1){
						g[u]+=g[k];
					}
				}
				if(g[u]==2) ans++;
			}
//			cout<<v<<' '<<ans<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
