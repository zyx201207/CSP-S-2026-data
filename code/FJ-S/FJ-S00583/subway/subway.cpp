#include<bits/stdc++.h>
using namespace std;
int c,n,d,m,p,w[100000],v,b,z,u,h,ans,ans1=100000;
bool vis[1000000];
vector<int> mm[100000],k[100000];
vector<int> zd[100000],zd1[100000];
void dfs(int u1){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ans+=w[u1];
	for(int j=0;j<zd[u1].size();j++){
		ans+=k[zd[u1][j]][zd1[u1][j]];
		for(int kk:mm[zd[u1][j]]){
			if(kk==h){
				ans+=zd1[kk];
				ans1=min(ans1,ans);
				return;
			}
		}
		for(int kk:mm[zd[u1][j]]){
			if(!vis[kk]){
				vis[kk]=1;
				dfs(kk);
				vis[kk]=0;
			}
			
		}
		ans-=k[zd[u1][j]][zd1[u1][j]];
	}
	ans-=w[u1];
}
int main(){
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v;
		for(int j=1;j<=v;j++){
			cin>>b;
			zd[b].push_back(i);
			
			mm[i].push_back(b);
			cin>>z;
			zd1[b].push_back(k[i].size());
			k[i].push_back(z);
		}
	}
	for(int i=1;i<=p;i++){
		cin>>u>>h;
		vis[u]=1;
		dfs(u);
		memset(vis,0,sizeof(vis));
		cout<<ans1<<endl;
		ans1=10000000;
		ans=0;
		
	}
	
	return 0;
}
