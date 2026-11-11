#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int c,t,n,i,j; ll ans,mn,a[N],d,cnt;
struct node {int v; ll w;};
vector<node> e[N];
void add(int u,int v,ll w) {e[u].push_back({v,w});}
void dfs(int u,ll s) {
	if(u==j) {
		if(s<mn) mn=s,cnt=0;
		if(s==mn) ++cnt;
		return ;
	}
	for(node v:e[u]) if(v.v<=j) dfs(v.v,s+v.w);
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d,ans=0;
		for(i=1;i<=n;++i) cin>>a[i];
		for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) {
			if(a[j]-a[i]<=d) add(i,j,1);
			else break ;
		}
		for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) 
			cnt=0,mn=LLONG_MAX,dfs(i,0),ans+=(cnt==2);
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 4
4 2
1 2 3 4
5 2 
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
4 2
1 2 3 4
*/
