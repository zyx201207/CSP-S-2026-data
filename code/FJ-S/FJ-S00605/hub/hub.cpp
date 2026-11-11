#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,l,r,mid,cnt,vis[1000002],dis,ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		pair<int,int>ed[n+2];
		vector<int>e[n+2];
		ans=n-1;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v),e[v].push_back(u),ed[i]={u,v};
		}
		for(int i=0;i<(1<<n);i++){
			queue<pair<int,int>>q;
			memset(vis,0,sizeof vis),cnt=dis=0;
			for(int j=0;j<n;j++){
				if((1<<j)&i)vis[j+1]=1,cnt++,q.push({j+1,0});
			}
			if(cnt!=k)continue;
			for(int i=1;i<n;i++)
				if(vis[ed[i].first]&&vis[ed[i].second])cnt--;
			if(cnt>2)continue;
			while(q.size()){
				int u=q.front().first,w=q.front().second;q.pop();
				for(int v:e[u])
					if(!vis[v])vis[v]=1,q.push({v,w+1}),dis=max(dis,w+1);
			}
			ans=min(ans,dis);
		}
		cout<<ans<<endl;
	}
	return 0;
}
