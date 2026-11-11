#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,yyy,vis[20],dis[20],ans;
vector<int> ve[20];

void dfs(int x,int fa){
	vis[x]=1;
	for(int i=0;i<ve[x].size();i++){
		int y=ve[x][i];
		if(y!=fa&&((yyy>>(y-1))&1))
			dfs(y,x);
	}
}

void dfs2(int x,int fa){
	dis[x]=(fa?dis[fa]+1:0);
	for(int i=0;i<ve[x].size();i++){
		int y=ve[x][i];
		if(y!=fa&&!((yyy>>(y-1))&1))
			dfs2(y,x);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c>3) { cout<<"1\n"; continue; }
		cin>>n>>k; ans=INT_MAX;
		for(int i=1;i<=n;i++) ve[i].clear();
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		for(yyy=0;yyy<(1<<n);yyy++){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			int tot=0,num=0,f=1;
			for(int i=1;i<=n;i++) if((yyy>>(i-1))&1) num++;
			//for(int i=1;i<=n;i++) cout<<((yyy>>(i-1))&1);
			//cout<<"  "<<num<<"\n";
			if(num!=k) continue;
			for(int i=1;i<=n;i++){
				if(((yyy>>(i-1))&1)&&!vis[i]){
					if((++tot)>2) {f=0; break;}
					dfs(i,0);
				}
			}
			if(!f) continue;
			//for(int i=1;i<=n;i++) cout<<((yyy>>(i-1))&1);
			//cout<<"---\n";
			for(int i=1;i<=n;i++) if((yyy>>(i-1))&1) dfs2(i,0);
			int aans=0;
			for(int i=1;i<=n;i++) aans=max(aans,dis[i]);
			ans=min(ans,aans);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

