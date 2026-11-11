#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,T,n,m,a[N],d[N],dp[N];
ll now,cnt,p,fro,ans;
vector<ll> g;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1,j=2;i<=n;i++){
			while(j<=n&&a[j]-a[i]<=m){
				d[j++]=d[i]+1;
			}
			if(a[i]+m<a[i+1]) d[i+1]=-1,j=i+2;
		}
		now=1,cnt=1,p=fro=ans=0;
		for(int i=1;i<=n;i++){
			if(d[i]==d[i+1]) ++cnt;
			else{
				if(d[i]==-1) g.push_back(-1);
				else g.push_back(cnt);
				cnt=1; now=i+1;
			}
		}
		cnt=g.size();
		for(int i=0;i<cnt;i++){
			if(g[i]==-1){
				ans+=p*fro;
				p=fro=0;
				continue;
			}
			p+=g[i];
			if(g[i]>2&&!fro) continue;
			if(g[i]>=2){
				ans+=fro*p;
				fro=p-g[i];
				p=0;
			}
		}
		printf("%lld\n",ans+p*fro);
		for(int i=1;i<=n;i++){
			d[i]=dp[i]=0;
		}
		g.clear();
	}
	return 0;
}
