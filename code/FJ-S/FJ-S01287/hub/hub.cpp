#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pint;
const int K=21,N=1e6+114;
int n,m,k,len[N],f[N];
vector<int> G[N];
void dfs1(int u,int fa,int& rt){
	len[u]=0;
	for(int v:G[u]){
		if(v!=fa){
			dfs1(v,u,rt);
			if(rt!=-1) return;
			len[u]=max(len[u],len[v]+1);
		}
	}
	if(len[u]==k) rt=u;
}
void dfs2(int u,int fa,int b,int& cnt){
	len[u]=0;
	for(int v:G[u]){
		if(v!=fa&&v!=b){
			dfs2(v,u,b,cnt);
			len[u]=max(len[u],len[v]+1);
		}
	}
	cnt+=(len[u]>=k);
}
int solve(int u,int fa){
	int rt=-1;
	dfs1(u,fa,rt);
//	cout << "solve: " << u << " " << fa << " " << rt << endl;
	if(rt==-1) return 1;
	int cnt=0;
	dfs2(rt,0,fa,cnt);
//	cout << "solve: " << u << " " << fa << " " << rt << " " << cnt << endl;
	return cnt;
}
bool check(int k_){
	k=k_;
	int ans=solve(1,0);
	for(int i=1;i<=n;++i){
		for(int j:G[i]){
			if(j>i){
				ans=min(ans,solve(i,j)+solve(j,i));
			}
		}
	}
	return ans<=m;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid,T;
	cin >> cid >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(m==n){
			cout << 0 << "\n";
			continue;
		}
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout << l << endl;
	}
	return 0;
}
