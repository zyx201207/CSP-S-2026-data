#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=11000;
ll c,t,n,d,m,a[N],res;
vector<ll> g[N];
void dfs1(int s,int t,int k){
	if(s==t){ m=k; rt; }
	for(int i=s+1;i<=t;i++){
		if(((a[i]-a[s])>d)&&i!=s+1){ dfs1(i-1,t,k+1); break; }
	}if(a[t]-a[s]<=d) dfs1(t,t,k+1);
}
void dfs(ll s,ll t,ll l){
	if(s==t&&l==m){ res++; rt; }
	for(int i=s+1;i<=t;i++){
		if((a[i]-a[s])<=d) dfs(i,t,l+1);
		else break;
	}
}
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[j]-a[i])<=d) g[i].push_back(j),g[j].push_back(i);
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			res=0,m=1e9;
			dfs1(i,j,0);
			if(m!=1e9) dfs(i,j,0);
			if(res==2) ans++;
		}
	}printf("%d\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(;t;--t) solve();
	rt 0;
}
