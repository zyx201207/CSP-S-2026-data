#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
namespace yyh{
	int sub,n,k;
	vector<int>g[105];
	bool v[105];
	int fa[105],dep[105];
	int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		if(x==y)return x;
		for(int i=dep[x]-dep[y];i>=1;i--)x=fa[x];
		if(x==y)return x;
		while(fa[x]!=fa[y]){
			x=fa[x];
			y=fa[y];
		}
		return fa[x];
	}
	void dfs(int x){
		v[x]=1;
		for(int j:g[x]){
			if(v[j])continue;
			dep[j]=dep[x]+1;
			fa[j]=x;
			dfs(j);
		}
	}
	void solve(){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i]=0,dep[i]=0,fa[i]=0,g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dep[1]=1;
		dfs(1);
		int U=(1<<n)-1,ans=n+1;
		for(int s=0;s<=U;s++){
			int h=0;
			if(__builtin_popcount(s)!=k)continue;
			for(int j=1;j<=n;j++){
				int t=n+1;
				for(int k=1;k<=n;k++)if(s&(1<<(k-1)))t=min(t,dep[j]+dep[k]-2*dep[lca(j,k)]);
				h=max(h,t);
			}
			ans=min(ans,h);
		}
		cout<<ans<<endl;
	}
	signed main(){
		int t;
		cin>>sub>>t;
		while(t--)solve();
		return 0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	yyh::main();
	cerr<<"Time: "<<(double)clock()<<"ms";
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
*/
