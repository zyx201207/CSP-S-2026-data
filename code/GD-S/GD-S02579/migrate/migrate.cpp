#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5010;
int c,n,d,t,x[N],lst[N],f[N][N],cnt[N][N],ans;
bool ps[N][N];
void solve(){
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++) lst[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cnt[i][j]=(j<=i),f[i][j]=0,ps[i][j]=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(lst[j]<=i) ps[i][lst[j]]=1;
			if(!ps[i][lst[j]]) continue;
			ps[i][j]=1;
			f[i][j]=f[i][lst[j]]+1;
			for(int k=max(lst[j],i),mv=f[i][lst[j]];f[i][k]==mv&&k<j;k++) cnt[i][j]+=cnt[i][k];
			if(cnt[i][j]==2) ans++;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}
