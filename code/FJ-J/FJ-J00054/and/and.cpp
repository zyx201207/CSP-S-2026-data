#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+3;
int n,m,a[MAXN];
int ans=0;
bool vis[MAXN];
inline void dfs(int sum,int pos){
	if(pos==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=true;
		dfs(sum&a[i],pos+1);
		vis[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		vis[i]=true;
		dfs(a[i],1);
		vis[i]=false;
	}
	cout << ans << '\n';
	return 0;
}
