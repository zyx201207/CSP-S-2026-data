#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
vector<int>g[N];
ll x[N],vis[N];
int n;
ll d;
void init(){
	for(int i=1;i<=n;i++){
		vis[i]=-1;
	}
}
bool bfs(int s,int e){
	init();
	queue<int>q;
	queue<ll>step;
	q.push(s);
	step.push(0);
	vis[s]=0;
	ll m=-1;
	ll cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ll st=step.front();
		step.pop();
		if(u==e){ 
			if(m==-1){
				m=st;
				cnt++;
			}
			else if(st==m){
				cnt++;
			}
			if(st>m){
				break;
			}
			if(cnt>2){
				return false;
			}
		}
		for(auto v:g[u]){
			if(vis[v]==-1||st+1<=vis[v]){
				vis[v]=st+1;
				q.push(v);
				step.push(st+1);
			}
		}
	}
	return cnt==2;
}
int main(){
	//30pts×óÓÒ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
