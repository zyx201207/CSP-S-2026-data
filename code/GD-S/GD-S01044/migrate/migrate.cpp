#include <bits/stdc++.h> 
using namespace std;
using ll =long long;
const ll inf=1e18+10;
const int N=1e6+5;
const int M=5005;
//hp 32pts
int c,t,n;
ll d;
ll p[N];
void solve(){
	ll ans=0;
	p[0]=-inf;
	for(int s=1;s<n;s++){
		int x=upper_bound(p+1,p+1+n,p[s]+d)-p-1;
		ll l=max(p[s]+d,p[x-2]+d);
		int r=p[x-1]+d;
		l=upper_bound(p+1,p+1+n,l)-p;
		r=upper_bound(p+1,p+1+n,r)-p-1;
		ans+=max(0ll,r-l+1);
//		cerr<<s<<" "<<l<<" "<<r<<'\n';
//	int x=upper_bound(p+1,p+1+n,p[s]+d)-p;
//	ans+=n-x+1;
	} cout<<ans<<'\n';
} 
ll f[M][M],g[M][M];
void init(int x){
	for(int i=x;i<=n;i++){
		for(int y=x;y<=n;y++){
			f[i][y]=inf;g[i][y]=0;
		}
	}
} 
void solve2(){
	//n^3
	ll ans=0;
	for(int i=1;i<=n;i++){
		init(i);
		f[i][i]=0;
		g[i][i]=1;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(p[k]-p[j]>d)break;
				if(f[i][j]+1<f[i][k]){
					f[i][k]=f[i][j]+1;
					g[i][k]=g[i][j];
				}else if(f[i][j]+1==f[i][k]){
					g[i][k]+=g[i][j];
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(g[i][j]==2&&f[i][j]!=inf)ans++;
		}
	}cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		if(13<=c&&c<=14)solve();
		else solve2();
	}
	
	return 0;
}
