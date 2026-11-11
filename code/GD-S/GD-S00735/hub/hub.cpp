#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;

vector<int> E[1000100];
queue<int> q;
int f[1000100],a[1100][1100];

void bfs(int s,int c){
	int u;
	q.push(s);
	f[s] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v : E[u]){
			if((c>>(v-1)&1) && !f[v]){
				f[v] = 1;
				q.push(v);
			}
		}
	}
}
void solve(){
	int n,k,u,v,ans=2e9;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		E[i].clear();
		for(int j = 1; j <= n; j++){
			a[i][j] = 1e9;
		}
		a[i][i] = 0;
	}
	for(int i = 1; i < n; i++){
		cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);
		a[u][v] = a[v][u] = 1;
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i = 1; i < (1<<n); i++){
		v = 0;
		for(int j = 1; j <= n; j++){
			v += i>>(j-1)&1;
		}
		if(v != k){
			continue;
		}
		int nossssssssssssssssssssssssss = 0;
		for(int j = 1; j <= n; j++){
			if(i>>(j-1) & 1){
				for(int _k = 1; _k <= n; _k++){
					f[_k] = 0;
				}
				bfs(j,i);
				for(int _k = 1; _k <= n; _k++){
					if((i>>(_k-1)&1) && !f[_k]){
						bfs(_k,i);
						break;
					}
				}
				int _ = 0;
				for(int _k = 1; _k <= n; _k++){
					if((i>>(_k-1)&1) && !f[_k]){
						_ = 1;
					}
				}
				if(_){
					nossssssssssssssssssssssssss = 1;
					break;
				}
				break;
			}
		}
		if(nossssssssssssssssssssssssss){
			continue;
		}
		int mx=0,d;
		for(int j = 1; j <= n; j++){
			if(i>>(j-1) & 1){
				continue;
			}
			d = 1e9;
			for(int _k = 1; _k <= n; _k++){
				if(!(i>>(_k-1) & 1)){
					continue;
				}
				d = min(d,a[j][_k]);
			}
			mx = max(mx,d);
		}
		ans = min(ans,mx);
	}
	cout<<ans<<'\n';
}
void SP_solve(){}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int yesssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss,T;
	for(cin>>yesssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss>>T; T--; yesssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss<=6 ? solve() : SP_solve());
	return 0;
}