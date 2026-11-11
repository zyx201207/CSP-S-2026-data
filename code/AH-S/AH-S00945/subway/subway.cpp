#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
vector<node> a[1005],b[1005];
int c,n,m,d,q,w[100005],v[10005],k,s,t,ans=0x3f3f3f3f,vv,ww;
void dfs(int x,int s){
	if(s>=ans)return;
	if(x==t){
		ans=min(ans,s);
		return ;
	}
	for(int i=0;i<b[x].size();i++){
		for(int j=0;j<a[b[x][i].v].size();j++){
			if(!v[a[b[x][i].v][j].v]){
				v[a[b[x][i].v][j].v]=1;
				dfs(a[b[x][i].v][j].v,s+a[b[x][i].v][j].w+b[x][i].w);
				v[a[b[x][i].v][j].v]=0;
			}
		}
	}
}
int	main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>vv>>ww;
			a[i].push_back(node{vv,ww});
			b[vv].push_back(node{i,ww});
		}
	}
	while(q--){
		memset(v,0,sizeof(v));
		cin>>s>>t;
		dfs(s,0);
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
