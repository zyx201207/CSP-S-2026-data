#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
const int M=1e5+10;
int c1,n,m,d,q;
int w[N];
int vis[N];
int a[510][111111];
int c[510][111111];
vector<pair<int,int> >e[N];
int dfs(int x,int y){
	int ans=0;
	for(auto u:e[x]){
		dfs(u.first,y);
			ans+=u.second;
		if(u.first==y){
			break;
		}
		
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>c[i][j];
			if(vis[a[i][j]]!=0){
				e[a[i][j-1]].push_back({a[i][j],vis[a[i][j]]+c[i][j]});
			}
			vis[a[i][j]]=c[i][j];
			if(j>1)e[a[i][j-1]].push_back({a[i][j],c[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y)<<'\n';
	}
	return 0;
} 
