#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,o[1005],fa[1005],u[1005],v[1005],dis[1005],anss;
vector<int>g[1000005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		anss=1e9;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		for(int i=0;i<(1<<n);i++){
			memset(o,0,sizeof o);
			int x=i,w=0;
			while(x){
				if(x&1)w++;
				x>>=1;
			}
			if(w!=k)continue;
			x=i;
			int j=0;
			while(x){
				j++;
				if(x&1)o[j]=1;
				x>>=1;
			}
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<n;i++){
				if(o[u[i]]&&o[v[i]]){
					fa[find(v[i])]=find(u[i]);
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(o[i]&&fa[i]==i){
					cnt++;
				}
			}
			if(cnt>2)continue;
			queue<pair<int,int>>q;
			for(int i=1;i<=n;i++){
				if(o[i]){
					dis[i]=0;
					q.push({0,i});
				}else{
					dis[i]=1e9;
				}
			}
			int ans=0;
			while(q.size()){
				auto i=q.front();
				q.pop();
				int d=i.first,u=i.second;
				if(d!=dis[u])continue;
				for(auto v:g[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push({dis[v],v});
					}
				}
			}
			for(int i=1;i<=n;i++){
				ans=max(dis[i],ans);
			}
			anss=min(anss,ans);
		}
		cout<<anss<<"\n";
	}
	return 0;
}
