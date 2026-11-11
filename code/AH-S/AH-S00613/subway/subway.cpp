#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int dp[505][505];
struct node{
	int v,w;
};
vector<int> g2[100005];
vector<node> g[100005];
vector<int> zz;
int st,fi,ans=0x3f3f3f3f;
bool vis[1000005];
void dfs(int now,int sum){
	for(auto it:g2[now]){
		sum+=g[it][now].w;
		for(auto it2:g[it]){
			if(it2.v==fi){
				ans=min(ans,sum+it2.w);
			}
		}
			for(auto it2:g[it]){
				if(g2[it2.v].size()>=2){
					for(int it3:g2[it2.v]){
						if(vis[it3])continue;
						vis[it3]=1;
						dfs(it2.v,sum+it2.w);
						vis[it3]=0;
					}
				}
			}
		sum-=g[it][now].w;
		}
		
	}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			g[i].push_back({v,w});
			g2[v].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(g2[i].size()>=2){
			zz.push_back(i);
		}
	}
	while(q--){
		
		cin>>st>>fi;
		ans=0x3f3f3f3f;
		dfs(st,0);
		cout<<ans+w[st]+w[fi]<<endl;
	}


    return 0;
}
