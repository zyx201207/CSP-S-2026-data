#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005
int n;
long long d,x[MAXN];
int pre[MAXN];
int f[MAXN],g[MAXN],h[MAXN];
void solve(){
	cin>>n>>d;
	x[0]=-1e18;
	pre[0]=1;
	for(int i=1;i<=n;++i){
		cin>>x[i];
		pre[i]=pre[i-1];
		while(x[i]-d>x[pre[i]])++pre[i];
		f[i]=g[i]=h[i]=0;
//		cerr<<i<<' '<<pre[i]<<'\n';
	}
	for(int i=1;i<n;++i){
		int p=pre[i],p2=pre[i+1];
		if(p<p2)f[i]+=f[p];
		f[i]+=1;
		f[i]+=max(p2-p-1,0);
	}
	for(int i=n;i>=1;--i){
		int p=pre[i];
		if(i+1<=n&&pre[i+1]==p){
			g[i]=0;
		}
		++g[i];
		if(p==i)continue;
		g[pre[i]]+=g[i];
		h[pre[i]]+=g[i];
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		if(pre[i]<i){
			int p=pre[i];
			if(pre[p]<p){
				int pp=pre[p];
				int tot=0;
				if(p+1<i){
					if(pre[p+1]==pp){
						if(p+2>=i||pre[p+2]>pp){
							tot+=f[pp];
//							cerr<<i<<' '<<f[pp]<<'\n';
						}
					}
					{
						int tmp=pre[p+1],tmp2=pre[p+2];
						tot+=max(tmp2-max(pp+1,tmp),0);
					}
				}
				auto b=1;
				if(i+1<=n&&pre[i+1]<=p+1);
				else b+=h[i];
//				cerr<<i<<' '<<tot<<' '<<b<<'\n'; 
				ans+=1ll*tot*b;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;while(t--)solve();
}
