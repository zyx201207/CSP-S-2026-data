#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
int w[N],l[N],a[N][N],t[N][N],ans,v[N][N];
bool vis[N];
vector<int> e[N];
void dfs(int x,int y,int id,int c){
	if(x==y){
		ans=min(ans,c);
		return ;
	}
//	cout<<x<<" "<<id<<" "<<c<<"\n";
	for(auto p:e[x]){
//		cout<<p<<"! ";
		for(int i=1;i<=l[x];i++){
//			cout<<a[p][i]<<" !";
			if(!vis[a[p][i]]) vis[a[p][i]]=1,dfs(a[p][i],y,p,c+t[id][a[p][i]]+t[p][x]+t[p][a[p][i]]),vis[a[p][i]]=0;
		}
//		cout<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int hzx,n,m,d,q;
	cin>>hzx>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[i][a[i][j]]=j;
			e[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e9;
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		dfs(x,y,0,0);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
