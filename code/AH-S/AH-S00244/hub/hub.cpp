#include<bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
int cid,T;
namespace sub1{
	const int N=20;
	int n,k,dist[N][N],p[N];
	vector<int>g[N];
	bool st[N],vis[N];
	void add(int a,int b){
		g[a].push_back(b);
	}
	int find(int x){
		return x!=p[x]?p[x]=find(p[x]):x;
	}
	void dfs(int u){
		vis[u]=true;
		for(int &j:g[u]){
			if(!vis[j]){
				//if(j==2&&u==1) cout<<"--------\n";
				//if(j==2||u==2) cout<<j<<" "<<u<<" "<<find(j)<<" "<<find(u)<<"\n";
				if(st[u]&&st[j]) p[find(j)]=find(u);
				dfs(j);
			}
		}
	}
	bool check(){
		for(int i=0;i<n;i++){
			vis[i]=false;
			p[i]=i;
		}
		dfs(0);
		set<int>se;
		for(int i=0;i<n;i++){
			if(st[i]) se.insert(find(i));
		}
		// if(st[1]==1&&st[2]==1&&st[8]==1){
		// 	cout<<find(1)<<" "<<find(2)<<" "<<find(8)<<"-----\n";
		// }
		return se.size()<=2;
	}
	void bfs(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=0x3f3f3f3f;
			}
		}
		queue<PII>q;
		for(int i=0;i<n;i++){
			if(st[i]){
				dist[i][i]=0;
				q.push({i,i});
			}
		}
		while(!q.empty()){
			int start=q.front().first;
			int u=q.front().second;
			q.pop();
			for(int &j:g[u]){
				if(dist[start][j]>dist[start][u]+1){
					dist[start][j]=dist[start][u]+1;
					q.push({start,j});
				}
			}
		}
	}
	void solve(){
		while(T--){
			cin>>n>>k;
			for(int i=0;i<n;i++) g[i].clear();
			for(int i=0;i<n-1;i++){
				int a,b;
				cin>>a>>b;
				a--,b--;
				//cout<<a<<" "<<b<<"\n";
				add(a,b);
				add(b,a);
			}
			int res=0x3f3f3f3f;
			for(int i=0;i<(1<<n);i++){
				if(__builtin_popcount(i)!=k) continue;
				for(int j=0;j<n;j++){
					st[j]=(i>>j&1);
				}
				if(!check()) continue;
				bfs();
				int now=0;
				for(int j=0;j<n;j++){
					int _=0x3f3f3f3f;
					for(int i=0;i<n;i++){
						if(st[i]){
							_=min(_,dist[i][j]);
							//cout<<i<<" "<<j<<" "<<dist[i][j]<<"\n";
						}
					}
					now=max(now,_);
				}
				res=min(res,now);
				// if(now==1){
				// 	for(int j=0;j<n;j++){
				// 		if(i>>j&1) cout<<j<<" ";
				// 	}
				// 	cout<<"\n";
				// }
			}
			cout<<res<<"\n";
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>cid>>T;
	if(cid>=0&&cid<=3) sub1::solve();
	return 0;
}