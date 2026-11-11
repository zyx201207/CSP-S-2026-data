#include <bits/stdc++.h>
using namespace std;
const int N=305;
int c,t;
int n,k,ans;
vector<int> mp[N];
int dis[N][N];
bool ch[N];
int fa[N];
int np[N][N];
int find(int p){
	if(fa[p]==p){
		return p;
	}
	return fa[p]=find(fa[p]);
}
void merge(int a,int b){
	int ra=find(a),rb=find(b);
	if(ra!=rb){
		fa[ra]=rb;
	}
}
void chk(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ch[i]&&ch[j]&&mp[i][j]){
				merge(i,j);
			}
		}
	}
	int cnt=0;
	bool vis[N]={false};
	for(int i=1;i<=n;i++){
		if(ch[i]&&(!vis[find(i)])){
			vis[find(i)]=true;
			cnt++;
		}
	}
	if(cnt>2){
		return;
	}
//	cout<<"# ";
//	for(int i=1;i<=n;i++){
//		cout<<vis[i]<<'\n';
//	}
//	cout<<'\n';
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!ch[i]){
			int mi=1e9;
			for(int j=1;j<=n;j++){
				if(j!=i&&ch[j]){
					mi=min(mi,dis[i][j]);
				}
			}
			sum=max(sum,mi);
			//cout<<sum<<'\n';
		}
	}
	ans=min(ans,sum);
}
void dfs(int p,int cnt){
	if(p==n+1){
		if(cnt==k){
			chk();
		}
		return;
	}
	ch[p]=true;
	dfs(p+1,cnt+1);
	ch[p]=false;
	dfs(p+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++){
			mp[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			np[u][v]=true;
			np[v][u]=true;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		for(int st=1;st<=n;st++){
			for(int i=1;i<=n;i++){
				dis[st][i]=1e9;
			}
			dis[st][st]=0;
			queue<pair<int,int> > qp;
			qp.push({0,st});
			while(!qp.empty()){
				int val=qp.front().first;
				int u=qp.front().second;
				//cerr<<"# "<<val<<' '<<u<<'\n';
				qp.pop();
				for(int nw:mp[u]){
					int v=nw;
					if(dis[st][v]>dis[st][u]+1){
						dis[st][v]=dis[st][u]+1;
						qp.push({dis[st][v],v});
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
