#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,a[2000005];
int f[2000005],g[2000005];
void dfs(int x){
	for(int k=x+1;k<=n;k++){
		if(a[k]-a[x]<=d){
			if(g[k]>g[x]+1){
				g[k]=g[x]+1;
				f[k]=f[x];
				dfs(k);
			}else if(g[k]==g[x]+1){
				f[k]+=f[x];
			}
		}else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[j]=0,g[j]=n+1;
			}
			f[i]=1;
			g[i]=0;
			dfs(i);
			for(int j=i+1;j<=n;j++){
				if(f[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
