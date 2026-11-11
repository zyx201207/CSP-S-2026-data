#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct node{
	int u,w;
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t){
		cin>>n>>k;
		vector<int>e[50005];
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}int ans=2000000;
		for(int i=1;i<=n;i++){
			int js=0;
			queue<node>q;
			q.push({i,0});
			while(!q.empty()){
					js++;
					if(js>=k){
						ans=min(ans,q.front().w*2);
						break;
					}
				for(int i=1;i<=e[q.front().u].size();i++){
					q.push({e[q.front().u][i],q.front().w+1});
				}
				q.pop();
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
} 
