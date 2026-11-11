#include<bits/stdc++.h>
using namespace std;
vector<int>e[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int minn=INT_MAX;
		for(int ma=0;ma<(1<<n);ma++){
			bool vis[50005];
			memset(vis,0,sizeof(vis));
			int cnt=0;
			for(int j=0;j<n;j++){
				if((ma>>j)){
					cnt++;
					vis[j+1]=1;
				}
			}
			if(cnt!=k)continue;
			int maxn=INT_MIN;	
			queue<pair<int,int> >q;
			for(int i=1;i<=n;i++){
				for(int i=1;i<=n;i++)if(vis[i])q.push({i,0});
			}
			while(!q.empty()){
				int u=q.front().first;
				int ww=q.front().second;
				q.pop();
				maxn=max(maxn,ww);
				for(int v:e[u]){
					if(vis[v])continue;
					vis[v]=true;
					q.push({v,ww+1});
				}
			}
			minn=min(minn,maxn);
		}
		cout<<minn<<'\n';
	} 
} 
