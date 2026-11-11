#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
inline ll read(){
	ll n=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return n*f;
}
const int N=2e6+5;
int n;
ll d;
ll a[N];
int f[N],g[N];
int cl[N],cr[N];
ll sl[N],sr[N];
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1,j=1;i<=n;i++){
		while(j<i && a[i]-a[j]>d) j++;
		f[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>i && a[j]-a[i]>d) j--;
		g[i]=j;
	}
	for(int i=1;i<=n;i++) cl[i]=cr[i]=0;
	for(int i=1;i<=n;i++) if(f[i]!=i) cr[f[i]]++;
	for(int i=1;i<=n;i++) if(g[i]!=i) cl[g[i]]++;
	for(int i=1;i<=n;i++){
		if(f[i]==i || g[f[i]]!=i) sl[i]=cl[i];
		else sl[i]=sl[f[i]]+cl[i];
	}
	for(int i=n;i>=1;i--){
		if(g[i]==i || f[g[i]]!=i) sr[i]=cr[i];
		else sr[i]=sr[g[i]]+cr[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		int j=i+1;
		ll l=cl[j];
		ll r=cr[i];
		if(g[i]==j) l--;
		if(f[j]==i) r--;
		int x=f[i];
		int y=g[j];
		if(x!=i && g[x]==j) l+=sl[x];
		if(y!=j && f[y]==i) r+=sr[y];
		ans+=l*r;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid=read(),T=read();
	while(T--) solve();
	
	return 0;
}
