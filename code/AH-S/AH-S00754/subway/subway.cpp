#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[1005];
vector<long long>a[1005];
vector<long long>t[1005];
bool f[500005];
long long dp[500005];
long long T;

long long adj[1005][1005]; 
void dfs(long long s,long long e){
	if(f[e])return;
	f[e]=true;
	for(long long i=1;i<=n;i++){
		bool flag=false;
		long long dt;
		for(long long j=0;j<k[i];j++){
			if(a[i][j]==e){
				flag=true;
				dt=t[i][j];
				break;
			}
		}
		if(!flag)continue;
		for(long long j=0;j<k[i];j++){
			if(a[i][j]==e)continue;
			if(dp[a[i][j]]>1e18){//long long
				dfs(s,a[i][j]);
			}
			dp[e]=min(dp[e],dp[a[i][j]]+t[i][j]+dt);//cout<<e<<' '<<dp[e]<<'\n'; 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long xxx,yyy;
			cin>>xxx>>yyy;
			a[i].push_back(xxx);
			t[i].push_back(yyy);
//			if(j==1)
//				adj[a[i][0]][a[i][1]]=adj[a[i][1]][a[i][0]]=t[i][0]+t[i][1];
		}
	}
	//quests aren't cinned
	if(c>=0 && c<=8 || c>11){//暴力 
		while(q--){
			long long s,e;
			cin>>s>>e;
			memset(dp,0x3f,sizeof dp);//ans要加进站的时间
			memset(f,false,sizeof f);
			//dp[i]表示从第s个地铁站的站厅第i个地铁站的站厅的最小时间
			//记忆化搜索
			dp[s]=0;
			dfs(s,e); 
			cout<<w[s]+dp[e]+w[e]<<'\n';
		}
	}
	if(c>=9 && c<=11){//A
		//转最短路
		long long maxn;
		memset(adj,0x3f,sizeof adj);
		for(long long i=1;i<=n;i++){
			adj[a[i][0]][a[i][1]]=adj[a[i][1]][a[i][0]]=t[i][0]+t[i][1];
			maxn=max(maxn,max(a[i][0],a[i][1]));
		}
		for(long long k=1;k<=maxn;k++){
			for(long long i=1;i<=maxn;i++){
				for(long long j=1;j<=maxn;j++){
					if(i==j || i==k || j==k)continue;
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
					adj[j][i]=min(adj[j][i],adj[j][k]+adj[k][i]);
				}
			}
		}
		while(q--){
			long long s,e;
			cin>>s>>e;
			cout<<w[s]+adj[s][e]+w[e]<<'\n';
		}
	}
	return 0;
}
