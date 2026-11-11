#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5,inf = 4e18;
int n,cc,d,t,k,bk[N],v[N],di[N];
vector<int> e[N];
void dfs(int x){
	v[x]=1;
	for(int y=0;y<e[x].size();y++){
		int j = e[x][y];
		if(v[j]||(!bk[j])) continue;
		dfs(j);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		e[i].clear(); 
	}
	for(int i = 1;i<n;i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = inf;
	for(int j = 0;j<(1<<n);j++){
		int cntt = 0;
		for(int i = 1;i<=n;i++){
			bk[i]=(1<<(i-1))&j;
			v[i]=0;
			if(!bk[i]) di[i]=inf;
			else di[i]=0,cntt++;
		}
		if(cntt!=k) continue;
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(!bk[i]) continue;
			if(v[i]) continue;
			if(++cnt>2) break;
			dfs(i);
		}
		if(cnt>2) continue;
		queue<int> q;
		for(int i = 1;i<=n;i++){
			if(bk[i]) q.push(i);
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int y=0;y<e[x].size();y++){
				int j = e[x][y];
				if(di[j]>di[x]+1){
					di[j]=di[x]+1;
					q.push(j);
				}
			}
		}
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			maxn=max(maxn,di[i]);
		}
		/*cout << maxn << " ";
		cout << "\n";*/
		ans=min(ans,maxn);
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> cc>>t;
	while(t--) solve();
	return 0;
}
