#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>t[100];
int vis[100];
bool gh[100];
bool fk[100];
int dis[100];
void ran(int dq){
	fk[dq]=1;
	for(auto i:t[dq]){
		if(vis[i]==1&&fk[i]==0)ran(i);
	}
}
struct node{
	int bian,dis;
};
void find(int c,int step){
	 queue<node>o;
	 o.push({c,0});
	 gh[c]=1;
	 dis[c]=0;
	 while(!o.empty()){
		 node s=o.front();
		 o.pop();
		 dis[s.bian]=min(dis[s.bian],s.dis+1);
		 for(auto i:t[s.bian]){
			 if(gh[i]==0){
				 o.push({i,s.dis+1});
				 gh[i]=1;
			 }
		 }
	 }
}
int gg=1e9;
void dfs(int cnt,int dq){
	if(cnt==k){
		memset(gh,0,sizeof(gh));
		for(int i=1;i<=100;i++)dis[i]=1e9;
		memset(fk,0,sizeof(fk));
		int ton=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1&&fk[i]==0){
				//cout<<i<<" "<<endl;
				ran(i);
				ton++;
			}
		}
		if(ton>2)return;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				for(int i=1;i<=100;i++)gh[i]=0;
				find(i,0);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dis[i]);
		}
		gg=min(gg,ans);
		return ;
	}
	if(dq==n+1)return ;
	 for(int i=dq;i<=n;i++){
		 vis[i]=1;
		 dfs(cnt+1,i+1);
		 vis[i]=0;
	 }
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//最优策略一定是尽量跳
	int c,tt;
	cin>>c>>tt;
	while(tt--){
        cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			t[a].push_back(b);
			t[b].push_back(a);
		}
		gg=1e9;
	    dfs(0,1);
	    cout<<gg-1<<endl;
	    for(int i=1;i<=n;i++)t[i].clear();
	}
    return 0;
}
//Oct31==Dec25?
