#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool vis[200005];
void dfs(int dep,int anss,int ii) {
	if(n-ii<m-dep) return;
	if(dep==m) {
		ans=max(ans,anss);
		return;
	}
	for(int i=ii+1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			dfs(dep+1,anss & a[i],i);
			vis[i]=0;
		}
	}
	return;
}
signed main() {//±©Á¦ËÑË÷£¬O(n^3)×óÓÒ
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int ans1;
			if(i!=1) ans1=a[1];	
			else ans1=a[2];
			for(int j=1;i<=n;j++){
				if(j==i) continue;
				ans1&=a[j];
			}
			ans=max(ans,ans1);
		}
	}
	else for(int i=1; i<=n; i++) dfs(1,a[i],i);
	cout<<ans;
	return 0;
}
