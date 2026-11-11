#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
int last;
int w[500005];
int k[505];
bool belong[500005][505];//belong[i][j]表示地铁站i是否在线路j上
int change[500005][25];//change[i][j]表示地铁站i的站厅走到线路j的站台需要的时间
vector<int> edge[500005];
bool vis[500005];
int sum,ans=INT_MAX;
void dfs(int u,int road){
	vis[u]=1;
	if(u==y){
		sum+=change[u][road];
		ans=min(ans,sum);
		sum-=change[u][road];
		return;
	}
	for(auto v:edge[u]){
		if(!vis[v]){
			if(road==0){
				for(int i=1;i<=n;++i){
					if(belong[u][i]&&belong[v][i]){
						road=i;
						break;
					}
				} 
				int spend1=0;
				spend1=change[u][road];
				sum+=spend1;
				dfs(v,road);
				road=0;
				sum-=spend1;
			}
			else{
				if(belong[v][road]){
					dfs(v,road);
				}
				else{
					int spend2=change[u][road];
					int nroad;
					for(int i=1;i<=n;++i){
						if(belong[u][i]&&belong[v][i]){
							nroad=i;
							break;
						}
					}
					spend2+=change[u][nroad];
					sum+=spend2;
					dfs(v,nroad);
					sum-=spend2;
				}
			}
			vis[v]=0;
		}
	}	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		last=0;
		for(int j=1;j<=k[i];++j){
			int a,t;
			cin>>a>>t;
			belong[a][i]=1;
			change[a][i]=t;
			if(j==1){
				last=a;
			}
			else{
				edge[a].push_back(last);
				edge[last].push_back(a);
				last=a;	
			}
		} 
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		ans=INT_MAX;
		sum=0;
		memset(vis,0,sizeof(vis));
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
