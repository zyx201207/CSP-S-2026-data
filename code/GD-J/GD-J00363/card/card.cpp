#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cy3[500005],vis[500005],ans[500005],tr[500005];
vector<int> q[500005];
void dfs(int i,int fa){
	tr[i]=1;
	for(int j=0;j<q[i].size();j++){
		if(q[i][j]!=fa){
			dfs(q[i][j],i);
			tr[i]+=tr[q[i][j]];
		}
	} 
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=200000&&m<=3000){
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==0) vis[a[i]]=i;
			cy3[i]=vis[a[i]];
		}
		for(int i=1;i<=n;i++){
			int j=i;
			while(j<=n){
				ans[a[j]]++;
				j=cy3[j]+1;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}else{
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==0){
				vis[a[i]]=i,cy3[i]=i+1;
				q[i].push_back(i+1);
				q[i+1].push_back(i);
			}
			else{
				cy3[i]=vis[a[i]];
				q[vis[a[i]]].push_back(i);
				q[i].push_back(vis[a[i]]);
			}
		}
		dfs(n,n+1);
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==i) ans[a[i]]=tr[i];
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' '; 
	}
	return 0;
}
