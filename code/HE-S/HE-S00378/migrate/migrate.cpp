#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[5005],Cnt[5005][5005],minn[5005][5005],ans;
vector<int> e[5005];
void dfs(int u,int v,int cnt){
	if(cnt!=0){
		if(cnt<minn[u][v]){
			minn[u][v]=cnt;
			Cnt[u][v]=1;
		}
		else if(cnt==minn[u][v]) Cnt[u][v]++;
	}
	for(int i=0;i<e[v].size();i++){
		if(e[v][i]==v) continue;
		dfs(u,e[v][i],cnt+1);
	} 
}
/*struct Node{
	int v,cnt;
}; 
void bfs(int pos){
	bool vis[5005];
	memset(vis,0,sizeof(vis));
	queue<Node> q;
	q.push(Node{pos,0});
	vis[pos]=1;
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		if(u.cnt!=0){
			if(u.cnt<minn[pos][u.v]){
				minn[pos][u.v]=u.cnt;
				Cnt[pos][u.v]=1;
			}
			else if(u.cnt==minn[pos][u.v]) Cnt[pos][u.v]++;
		}
		for(int i=0;i<e[u.v].size();i++){
			if(!vis[e[u.v][i]]){
				q.push(Node{e[u.v][i],u.cnt+1});
				vis[e[u.v][i]]=1;
			}
		}
	}
}why my bfs is false*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c;
	if(c>10){
		cout << 0;
		return 0;
	}
	cin >> T;
	while(T--){
		cin >> n >> d;
		memset(Cnt,0,sizeof(Cnt));
		a[0]=-1e18-5; 
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) minn[i][j]=1e18+5;
		}
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			cin >> a[i];
			int pos=lower_bound(a+1,a+i+1,a[i]-d)-a;
			for(int j=pos;j<i;j++) e[j].push_back(i);
		}
		ans=0;
		/*for(int i=1;i<n;i++){
			for(int j=0;j<e[i].size();j++) cout << i << " " << j << " ";
		}*/
		for(int i=1;i<n;i++){
			//bfs(i);
			dfs(i,i,0);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				//printf("%ld %ld : %ld %ld\n",i,j,Cnt[i][j],minn[i][j]);
				if(Cnt[i][j]==2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;//poor[8,24]pts at T3 
}
