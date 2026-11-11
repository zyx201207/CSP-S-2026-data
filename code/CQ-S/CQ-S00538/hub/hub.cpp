#include<bits/stdc++.h>
using namespace std;
bool OP;
namespace cs{
	#define LL long long
	#define fir first
	#define sec second
	typedef pair<int,int> PII;
	const int N=1e6;
	const int INF=2e9;
	int Case,T,n,k,maxd[N+5],ans;
	vector<int> v[N+5];
	void dfs(int rt,int prt){
		maxd[rt]=0;
		for(auto u:v[rt]){
			if(u==prt) continue;
			dfs(u,rt);
			maxd[rt]=max(maxd[rt],maxd[u]+1);
		}
	}
	int siz[N+5],tid[N+5],tcnt;
	int dp[4005][4005];
	void DP(int rt,int prt){
		for(int i=1;i<=n;i++){
			dp[rt][i]=INF;
		}
		siz[rt]=1;
		tid[rt]=++tcnt;
		dp[rt][1]=0;
		for(auto u:v[rt]){
			if(u==prt) continue;
			DP(u,rt);
			for(int i=siz[rt];i>=1;i--){
				for(int j=siz[u];j>=1;j--){
					dp[rt][i+j]=min(dp[rt][i+j],max(dp[rt][i],dp[u][j]));
				}
				dp[rt][i]=max(dp[rt][i],maxd[u]+1);
			}
			siz[rt]+=siz[u];
		}
	}
	int dist[4005][4005];
	queue<int> qu;
	void bfs(int s){
		for(int i=1;i<=n;i++){
			dist[s][i]=INF;
		}
		dist[s][s]=0;
		qu.push(s);
		int fr;
		while(!qu.empty()){
			fr=qu.front();
			qu.pop();
			for(auto u:v[fr]){
				if(dist[s][u]==INF){
					dist[s][u]=dist[s][fr]+1;
					qu.push(u);
				}
			}
		}
	}
	void Init(){
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		tcnt=0;
		ans=INF;
	}
	int main(){
		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		cin>>Case>>T;
		int x,y,temp;
		while(T--){
			Init();
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>x>>y;
				v[x].push_back(y);
				v[y].push_back(x);
			}
			for(int i=1;i<=n;i++){
				bfs(i);
			}
			for(int root=1;root<=n;root++){
				tcnt=0;
				dfs(root,0);
				DP(root,0);
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						temp=INF;
						for(int l=1;l<k;l++){
							temp=min(temp,max(dp[i][l],dp[j][k-l]));
						}
						for(int l=1;l<=n;l++){
							if(tid[l]>=tid[i]&&tid[l]<tid[i]+siz[i]) continue;
							if(tid[l]>=tid[j]&&tid[l]<tid[j]+siz[j]) continue;
							temp=max(temp,min(dist[i][l],dist[j][l]));
						}
						ans=min(ans,temp);
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
bool ED;
int main(){
	cs::main();
	cerr<<"Memory:"<<abs(&OP-&ED)/1000.0/1000<<"MB\n";
	return 0;
}

