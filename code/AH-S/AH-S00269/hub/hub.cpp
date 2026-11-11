#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
ll C,T;
ll n,k,ans,tans;
bool g[N][N];
bool flag[N],vis[N];
void dfs1(ll p){
	vis[p]=true;
	for(ll i=1;i<=n;i++)
		if(g[p][i]&&flag[i]&&!vis[i]) dfs1(i);
}
bool th(){
	ll cnt=0;
	memset(vis,false,sizeof vis);
	for(ll i=1;i<=n;i++)
		if(flag[i]&&!vis[i]){
			cnt++;
			dfs1(i);
		}
	return cnt<=2;
}
ll AC(ll s){
	vis[s]=true;
	ll maxn1=0,maxn2=0;
	for(ll i=1;i<=n;i++)
		if(flag[i]&&g[s][i]&&!vis[i]){
			ll p=AC(i)+1;
			if(p>maxn1){
				maxn2=maxn1;
				maxn1=p;
			}
			else if(p>maxn2) maxn2=p;
		}
	if(maxn1!=0) ans=max(ans,maxn1+maxn2);
	return maxn1;
}
void check(){
	if(!th()) return;
	for(ll i=1;i<=n;i++)
		if(flag[i]){
			ans=0;
			memset(vis,false,sizeof vis);
			AC(i);
			tans=min(tans,ans);
			break;
		}
}
void dfs(ll p,ll k){
	if(k==0){
		check();
		return;
	}
	if(p>n) return;
	dfs(p+1,k);
	flag[p]=true;
	dfs(p+1,k-1);
}
void solve(){
	tans=0x3f3f3f3f3f3f3f3f;
	memset(g,false,sizeof g);
	cin>>n>>k;
	for(ll i=1;i<n;i++){
		ll x,y;
		cin>>x>>y;
		g[x][y]=g[y][x]=true;
	}
	dfs(1,k);
	cout<<tans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
