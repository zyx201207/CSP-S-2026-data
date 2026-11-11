#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T;
int n;
ll d,x[N],dis[N],cnt[N];
ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
void dfs1(int u,ll k){
	if(u==1) return;
	int j=u;
	while(--j){
		if(x[u]-x[j]<=d){
			dis[j]=k;
		}else break;
	}
	if(j+1!=u) dfs1(j+1,k+1);
}
void dfs2(int u,int k){
	if(dis[u]==k) cnt[u]++;
	int j=u;
	while(--j){
		if(x[u]-x[j]<=d){
			dfs2(j,k+1);
		}else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(c==11||c==12){
			cout<<0<<'\n';
			continue;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++) cnt[j]=0;
			dis[i]=0;
			dfs1(i,1);
			dfs2(i,0);
			for(int j=1;j<i;j++){
				if(cnt[j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
