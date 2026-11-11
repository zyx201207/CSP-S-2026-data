#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[1010],anss=1e18;
vector<int>t[1010],g[1010];
int vis[1010],p[1010];
void dfs(int k,int n,int an){
	if(k==n){
		anss=min(anss,an);
	}
	for(int i=0;i<t[k].size();i++){
		if(!vis[t[k][i]]){
			vis[t[k][i]]=1;
			dfs(t[k][i],n,an+g[k][i]+p[k]);
			vis[t[k][i]]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin >>a>>b;
			if(i==a)p[a]=b;
			t[i].push_back(a);
			g[i].push_back(b);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=0;
		anss=1e18;
		cin >>x>>y;
		dfs(x,y,0);
		cout<<anss+w[x]+w[y]<<endl;
	}
	return 0;
}
