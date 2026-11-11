#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,d,c,m,q,s,e;
long long w[N],t[510][N],ans=0x3f3f3f3f3f3f3f3f,vis[N];
vector<pair<int,int>>mp[N];
void dfs(int u,int num,int sum,int fa){
	if(vis[u])return;
	if(sum>=ans)return;
	if(u==e){
		ans=min(ans,sum+t[num][u]);
		return;
	}
	vis[u]=1;
	for(auto v:mp[u]){
		int x=v.first,y=v.second;
		if(y==num){
			dfs(x,y,sum,u);
		}else{
			dfs(x,y,sum+t[num][u]+t[y][u],u);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		long long x,y,ox;
		for(int j=1;j<=k;j++){
			if(j==1){
				cin>>ox>>y;
				t[i][ox]=y;
				continue;
			}else{
				cin>>x>>y;
				mp[ox].push_back({x,i});
				mp[x].push_back({ox,i});
				t[i][x]=y;
				ox=x;
			}
		}
	}
	while(q--){
		ans=0x3f3f3f3f3f3f3f3f;
		memset(vis,0,sizeof vis);
		cin>>s>>e;
		dfs(s,0,0,0);
		cout<<ans+w[s]+w[e];
	}
	
	return 0;
}
