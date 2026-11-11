#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
bool vis[1000005],dis[1000005];
vector<int>e[100005];
int dfs(int cnt,int num){
	int ma1=0,ma2=0;
	vis[num]=1;
	dis[num]=cnt;
	if(e[num].size()==1&&num!=1)return cnt;
	for(int i:e[num]){
		if(!vis[i]){
			int k=dfs(cnt+1,i);
			if(k>ma1){
				ma1=k;  
			}
			else ma2=max(ma2,k);
		}
	}
	
	if(num==1)return ma1+ma2;
	else return ma1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<dfs(0,1)/3; 
	}
} 
