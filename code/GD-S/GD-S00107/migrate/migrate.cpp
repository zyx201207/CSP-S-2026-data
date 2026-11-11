#include <iostream>
#include <vector>
using namespace std;
const int N=2e6+5;
int c,t,n,en,mn,res;
unsigned long long d,x[N];
vector<int> g[N];
void dfs(int u,int step){
	if(step>mn||x[en]<x[u]) return;
	if(u==en){
		if(mn>step){
			mn=step;
			res=1;
		}
		else if(mn==step) res++;
		return;
	}
	for(int i=0;i<g[u].size();i++){
		dfs(g[u][i],step+1);
	}
	return;
}
void init(){
	for(int i=1;i<=n;i++) g[i].clear();
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){	
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		init();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].push_back(j);
			}
		}
		int ans=0;
		for(int l=1;l<n;l++){
			for(int r=l+1;r<=n;r++){
				res=0;
				mn=1e9;
				en=r;
				dfs(l,0);
				if(res==2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
