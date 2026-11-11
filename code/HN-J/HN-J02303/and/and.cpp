#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int ans = -1;
bool vis[200010];
int dis[200010];
int len;
void dfs(int u,int cnt,int step){
	dis[++len] = u;
	if(cnt == m){
		ans = max(ans,step);
		for(int i = 1;i <= m;i ++){
			cout<<dis[i]<<' '<<endl;	 
		}
		cout<<step<<' '<<ans<<endl;
	}
	for(int i = u + 1;i <= n;i ++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(i,cnt + 1,step & a[i]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	for(int i = 1;i <= n - m + 1;i ++){
		fill(vis + 1,vis + n + 1,0);
		len = 0;
		dfs(i,1,a[i]);
	}
	cout<<ans;
}
