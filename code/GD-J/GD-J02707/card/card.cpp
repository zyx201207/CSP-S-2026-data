#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool vis[5005];
int ans[5005];

int main(){//err

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof vis);
		stack<int>v[5005];
		for(int j=i;j<=n;++j){
			int val=a[j];
			if(!vis[val]){
				vis[val]=1;
				v[val].push(j);
			}
			else{
				
				//for(int j=0;j<v[val].size();++j)vis[v[val][j]]=0;
				while(v[val].size())vis[v[val].top()]=0,vis[v[val].top()-1]=0,v[val].pop();
				//for(int j=0;j<v[val-1].size();++j)vis[v[val][j]]=0;
				
				//memset(vis,0,sizeof vis);
				vis[val]=1;
				v[val].push(j);
			}
			//for(int j=1;j<=m;++j)cerr<<vis[j];
		}
		for(int j=1;j<=m;++j){
			if(vis[j])++ans[j];
		}
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';//,cerr<<ans[i]<<' ';
	return 0;
}
