//and
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N=1e5+5,M=5*N,K=5000;
ll n,m,a[M],ans;
bool vis[M];
void dfs(int u,int v){
	if(u==n+1){
		if(v!=m) return ;
		ll cnt=2147483647;
		for(int i = 1;i<=n;i++){
			if(vis[i]==1){
				cnt&=a[i];
			}
		}
		ans=max(ans,cnt);
		return ;
	}
	vis[u]=1;
	dfs(u+1,v+1);
	vis[u]=0;
	dfs(u+1,v);
	return ; 
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	dfs(1,0);
	cout << ans;
	return 0;
}
