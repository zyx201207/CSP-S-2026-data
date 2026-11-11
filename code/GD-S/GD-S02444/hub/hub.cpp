#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int>> edge(n+1);
		vector<vector<int>> dis(n+1,vector<int>(n+1,1e9));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int md=1;md<=n;md++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][md]+dis[md][j]);
			}
		}
		auto chk=[&](const vector<int> &pos)->bool {
			vector<vector<int>> nedge(n+1);
			vector<int> du(n+1,0);
			for(auto x:pos){
				for(auto v:edge[x]){
					int flag=0;
					for(auto y:pos){
						if(y==v){
							flag=1;
							break;
						}
					}
					if(!flag) continue;
					nedge[x].push_back(v);
					nedge[v].push_back(x);
					du[x]++,du[v]++;
				}
			}
			int sum=0;
			for(auto x:pos) sum+=du[x];
			int cha=(pos.size()-1)*2-sum;
			if(cha/2<=1) return 1;
			return 0;
		};
		if(k==2){
			int ans=1e9;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int mx=0;
					for(int nw=1;nw<=n;nw++) mx=max(mx,min(dis[i][nw],dis[j][nw]));
					ans=min(ans,mx);
				}
			}
			cout<<ans<<'\n';
		}
		else{
			int ans=1e9;
			for(int msk=0;msk<(1<<n);msk++){
				if(__builtin_popcount(msk)!=k) continue;
				vector<int> pos;
				for(int i=0;i<n;i++){
					if(msk>>i&1) pos.push_back(i+1);
				}
				if(!chk(pos))  continue;
				int mx=0;
				for(int i=1;i<=n;i++){
					int mn=1e9;
					for(auto x:pos) mn=min(mn,dis[i][x]);
					mx=max(mx,mn);
				}
				ans=min(mx,ans);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
//J:100+100+[50,75]+48=[298,323]
//S:100+12+16+20=148
