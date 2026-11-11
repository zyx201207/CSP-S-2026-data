#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,k;
vector<int> G[N];
int dp[N][5];
int ldep[N],tk[N];
int cnt,cct[N];
vector<int> vec;
void dfs(int p,int f,int d){
	ldep[p]=0;
	tk[p]=0;
	for(auto j:G[p]){
		if(j==f) continue;
		dfs(j,p,d);
		ldep[p]=max(ldep[p],ldep[j]+1);
		if(tk[j]) tk[p]=1;
	}
	if(ldep[p]<d) return;
	ldep[p]=-1;
	tk[p]=1;
	cnt++;
	for(auto j:G[p]){
		if(j==f) continue;
		if(tk[j]) cct[ldep[j]+1]++;
	}
}
inline bool check(int x){
	cnt=0;
	for(int i=0;i<=n;i++) cct[i]=0;
	vec.clear();
	dfs(1,0,x);
	int Cnt=cnt,idx=0;
	while(cnt>2){
		while(cct[idx]==0) idx++;
		Cnt+=idx;
		cnt--;
		cct[idx]--;
	}
	return Cnt<=k;
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int L=0,R=n;
	while(L<R){
		int mid=L+R>>1;
		if(check(mid)) R=mid;
		else L=mid+1; 
	}
	cout<<L<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
