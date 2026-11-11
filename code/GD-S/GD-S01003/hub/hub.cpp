#include <bits/stdc++.h>
using namespace std;
vector<int> ve[1000005];
struct node{
	int p,t;
};
bool vis[1000005];
int dist(int s,int t){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push({s,0});
	while(q.size()){
		node r=q.front();
		q.pop();
		if(r.p==t){
			return r.t;
		}
		for(int i=0;i<ve[r.p].size();i++){
			if(!vis[ve[r.p][i]]){
				q.push({ve[r.p][i],r.t+1});
			}
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		int ans=dist(1,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i==1 && j==1){
					continue;
				}
				ans=min(ans,dist(i,j));
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
