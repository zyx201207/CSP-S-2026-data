#include"bits/stdc++.h"
using namespace std;
int c,n,m,q,d,ans=1e9+7;
struct station{
	int w,t[505];
}a[500005];
struct path{
	int k,s[500005];
}b[505];
void dfs(int from,int to,int res){
	if(from==to){
		ans=min(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i].k;j++){
			if(b[i].s[j]==from){
				res+=a[from].t[i];
				for(int l=1;l<=b[i].k;l++){
					res+=a[l].t[i];
					dfs(l,to,res);
					res-=a[l].t[i];
				} 
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].k;
		for(int j=1;j<=b[i].k;j++){
			cin>>b[i].s[j]>>a[j].t[i];
		}
	}
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ans=1e9+7;
		dfs(u,v,a[u].w+a[v].w);
		cout<<ans<<"\n";
	}
	return 0;
}
