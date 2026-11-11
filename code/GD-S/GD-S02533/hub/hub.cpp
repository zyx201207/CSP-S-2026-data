#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int MAXN=1e6+5;
int c,t,n,k,fa[MAXN],dep[MAXN];
vector<int>e[MAXN];
void solve1(){
}
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}
bool check(int mid){
	int root=1;
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	for(int q=1;q<=2;q++){
		memset(fa,0,sizeof(fa));
		memset(dep,0,sizeof(dep));
		dfs(root);
		int deep=0;
//		if(mid==1)for(int i=1;i<=n;i++)cout<<dep[i]<<" ";
//		cout<<"\n\n";
		for(int i=1;i<=n;i++)
			if(dep[deep]<dep[i]&&vis[i]==0)
				deep=i;
//		cout<<mid<<" "<<deep<<"\n";
		int f=deep;
//		cout<<"	"<<f<<"\n";
		for(int i=1;i<=mid;i++){
			if(f==root)return 1;
			f=fa[f];
		}
//		if(mid==1)for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
		if(f==root)return 1;
//		if(mid==1)cout<<"234";
		if(q==2&&vis[f]==1)return 1;
		memset(dep,0,sizeof(dep));
		dfs(f);
		for(int i=1;i<=n;i++)
			if(dep[i]<=mid)
				vis[i]=1;
//		if(q==2&&mid==1){
//			if(mid==1){
//				for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
//				cout<<"\n\n";
//			}
//				if(vis[i]==0)
//					return 0;
//			return 1;
//		}
		root=f;
	}
	return 0;
}
void solve2(){
	int l=0,r=1e9,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<"\n";
}
void calc(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
//	if(c==1)solve1();
//	else if(c==7||c==11||c==12)
	solve2();
//	else solve1();
}
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)calc();
	return 0;
}
/*
0 2
 5 2
 1 2
 2 3
 3 4
 4 5
 
 10 3
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 3 8
 7 9
 9 10
T4 hub
1 暴力n选k O(10^4)  判断是否可行 O(N)  k个点加入queue跑bfs求最小值 O(N) 
7,11~12 二分：
	二分最小答案mid
	check判断能否使每一个点的 通勤距离 <=mid
	bool check(int mid){
		int root=1;
		重复2次 
			以root为根dfs
			int deep=深度最深的点
			int f=deep的k级祖先
			if(f不存在)return 1; 
			root=f;
		return 0;
	}
*/
