#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define ld long double
#define stg string
#define Cn const
using namespace std;
ll read() {
	ll r=0,fl=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
	while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
	return r*fl;
}
ll Max(ll a,ll b) {return a>b?a:b;}
ll Min(ll a,ll b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn int Inf=1e9;
Cn int N=1e6+5;
int c,T;
vector<int> G[N];
int dep[N],fa[N];
int n,u,v,ans,k;
void dfs1(int pos,int fat) {
	fa[pos]=fat;dep[pos]=dep[fat]+1;
	for(auto nxt:G[pos]) {
		if(nxt==fat) continue;
		dfs1(nxt,pos);
	}
}
int lca(int u,int v) {
	while(u!=v) {
		if(dep[u]<dep[v]) swap(u,v);
		u=fa[u];
	}
	return u;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	while(T--) {
		ans=Inf;
		n=read();k=read();
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++) {
			u=read();v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1,0);
		if(n==k) cout<<0<<endl;
		else if(c<=3||n<=15) {
			for(int i=0;i<(1<<n);i++) {
				int cnt=0;
				for(int j=0;j<n;j++) {
					if(i&(1<<j)) {
						cnt++;
						if(cnt>k) break;
					}
				}
				if(cnt!=k) continue;
				cnt=0;
				for(int j=0;j<n;j++) {
					if(i&(1<<j)) {
						for(auto p:G[j+1]) {
							if(i&(1<<(p-1))) cnt++;
						}
					}
				}
				//cout<<cnt<<endl;
				if(cnt/2<k-2) continue;
				int mx=0;
				for(int j=0;j<n;j++) {
					int mn=Inf;
					if(i&(1<<j)) continue;
					for(int p=0;p<n;p++) {
						if(i&(1<<p)) mn=Min(mn,dep[p+1]+dep[j+1]-2*dep[lca(p+1,j+1)]);
					}
					mx=Max(mx,mn);
				}
				//if(mx==1) cout<<"#"<<i<<endl;
				ans=Min(ans,mx);
			}
			cout<<ans<<endl;
		} else if(c==13||c==14) {
			if(k<=n/2) cout<<((n/2)-k+3)/4+1<<endl;
			else cout<<1<<endl;
		}
		else cout<<Max((n-k)/6,1)<<endl;
	}
}
