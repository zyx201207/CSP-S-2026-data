#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const int INF=0x3f3f3f3f;
int c,T,n,L[N],ans,f[5005][5005],mi[N];
ll a[N],D;
void dfs(int o,int stp){
	mi[o]=min(mi[o],stp);
	++f[o][stp];
	for(int i=o+1;i<=n&&a[i]-a[o]<=D;++i)
		dfs(i,stp+1);
}
void solve(){
	scanf("%d%lld",&n,&D);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	int p=1;
	for(int i=1;i<=n;++i){
		while(a[i]-a[p]>D) ++p;
		L[i]=p;
	}
	if(0<=c&&c<=10){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
			for(int k=0;k<=n;++k)
				f[j][k]=0;
			for(int j=1;j<=n;++j) mi[j]=INF;
			dfs(i,0);
			for(int j=i;j<=n;++j)
				if(mi[j]<INF&&f[j][mi[j]]==2) ++ans;
		}
		printf("%d\n",ans);
		ans=0;
		return;
	}
	if(11<=c&&c<=12){
		ll k=D/(a[2]-a[1]);
		if(k<=1) printf("0\n");
		else printf("%lld\n",-k-k+1+n);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
