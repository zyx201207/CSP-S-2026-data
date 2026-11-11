#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+7,N=5e2+7;
int c,t;
int n,k;
vector<int> g[N];
int a[N];
int lt;
vector<int> cod[N];
int F[N];
int mn;
void dfs(int u,int fa){
	if(a[fa]==0){
		lt++;
	}
	F[u]=fa;
	cod[lt].push_back(u);
	for(int i:g[u]){
		if(i!=fa){
			dfs(i,u);
		}
	}
	return ;
}
void dist(int u,int fa,int v,int pl){
	if(u==v){
		mn=min(mn,pl);
//		cout<<mn<<"* ";
		return ;
	}
	for(int i:g[u]){
		if(i!=fa){
			dist(i,u,v,pl+1);
		}
	}
	return ;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		g[i].clear();
	int ans=1e18;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int mask=1;mask<=(1<<n)-1;mask++){
		memset(a,0,sizeof(a));
		int t=mask;
		int i=0;
		int w=0;
		while(t){
			i++;
			if(t%2){
				w++;
				a[i]=1;
			}
			t/=2;
		}
		if(w==k){
			for(int p=1;p<=lt;p++)
				cod[p].clear();
			lt=0;
			dfs(1,0);
			if(lt==2){
				mn=1e18;
				for(int p:cod[1]){
					for(int q:cod[2]){
						dist(p,F[p],q,0);
					}
				}
				ans=min(ans,mn);
			}
		}
	}
	cout<<ans/2<<"\n";
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
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
