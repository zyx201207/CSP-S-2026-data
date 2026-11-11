#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
#define int long long
using namespace std;
const int N=2e6+5,INF=0x3f3f3f3f;
int c,T,n,d,cnt;
int a[N];
vector<int> g[N];
void BFS(int st){
	queue<int> q;
	vector<int> d(n+2,0),vis(n+2,0);
	//最短路，访问次数 
	q.push(st);
	d[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(d[v]==0){
				vis[v]++;
				d[v]=d[u]+1;
				q.push(v);
			}else if(d[u]+1==d[v]){
				vis[v]++;
				if(vis[v]==2)cnt++;
				else if(vis[v]>2)cnt--;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		vector<int> deg(n+2,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
				g[i].push_back(j);
				if(T==3)cout<<i<<" "<<j<<endl;
				deg[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			BFS(i);
			ans+=cnt;
			if(T==3)cout<<i<<":"<<cnt<<endl;
		}
		cout<<ans<<endl;
	}
}
