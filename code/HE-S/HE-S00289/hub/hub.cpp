#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+5;
int c,T,n,k,dis[1005][1005],ans,fa[N],dep[N];
vector<int> p[N];
void dfsk2(int u,int fa){dep[u]=dep[fa]+1;for(int v:p[u])if(v!=fa) dfsk2(v,u);}
void solvek2(){
	int rt=1;dfsk2(1,0);F(i,1,n)if(dep[i]>dep[rt]) rt=i;
	dfsk2(rt,0);rt=1;F(i,1,n)if(dep[i]>dep[rt]) rt=i;
	cout<<dep[rt]/4<<'\n';
}int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int cknum(int S){
	F(i,1,n) fa[i]=i;
	F(i,1,n)if(S>>i-1&1)F(j,1,n)if(S>>j-1&1)if(dis[i][j]==1&&find(i)!=find(j)) fa[find(i)]=find(j);
	int cnt=0;F(i,1,n)if(S>>i-1&1) cnt+=(fa[i]==i);
	return cnt; 
}void dfs_baoli(int u,int S,int cnt){
	if(cnt>k) return;
	if(u==n+1){
		if(u==n+1&&cknum(S)<=2&&cnt==k){
			int res=0;
			F(i,1,n){
				int val=N;F(j,1,n)if(S>>j-1&1) val=min(val,dis[i][j]);
				res=max(res,val);
			}ans=min(ans,res);
		}return;
	}dfs_baoli(u+1,S,cnt),dfs_baoli(u+1,S|1<<u-1,cnt+1);
}void baoli(){
	F(i,1,n)F(j,1,n)dis[i][j]=N;F(i,1,n) dis[i][i]=0;ans=N;
	F(i,1,n) fa[i]=i;
	F(i,1,n)for(int v:p[i]) dis[i][v]=1;
	F(k,1,n)F(i,1,n)F(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs_baoli(1,0,0);cout<<ans<<'\n';
}void solve(){
	cin>>n>>k;F(i,1,n) p[i].clear();
	F(i,2,n){int u,v;cin>>u>>v,p[u].push_back(v),p[v].push_back(u);}
	if(n<=10) baoli();else if(k==2) solvek2();
}int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;while(T--) solve();
	return 0;
}

