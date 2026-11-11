#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dop(i,l,r) for(int i=l;i>=r;i--)
#define _ 1000006
using namespace std;
int c,t,n,k,deep[_],f[_][21],lg,ans=INT_MAX;
queue<int>q;
bool vis[_],chose[_];
vector<int>a[_];
void init(){
	q.push(1);
	vis[1]=true;
	deep[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int len=a[u].size();
		rep(i,0,len-1){
			int v=a[u][i];
			if(vis[v])
				continue;
			vis[v]=true;
			q.push(v);
			deep[v]=deep[u]+1;
			f[v][0]=u;
			rep(j,1,20)
				f[v][j]=f[f[v][j-1]][j-1];
		}
	}
}
int lca(int u,int v){
	if(deep[u]<deep[v])
		swap(u,v);
//	cout<<u<<' '<<v<<endl;
	dop(j,lg,0)
		if(deep[f[u][j]]>=deep[v])
			u=f[u][j];
	if(u==v)
		return u;
//	cout<<u<<' '<<v<<endl;
	dop(j,lg,0)
		if(f[u][j]!=f[v][j]){
			u=f[u][j];
			v=f[v][j];
		}
	return f[u][0];
}
int dis(int u,int v){
	return deep[u]+deep[v]-2*deep[lca(u,v)];
}
int count(){
	int D=0;
	vector<int>chosen;
	rep(i,1,n)
		if(chose[i])
			chosen.push_back(i);
//	rep(j,0,k-1)
//		cout<<chosen[j]<<' ';
//	cout<<endl;
	rep(i,1,n){
		if(chose[i])
			continue;
		int d=INT_MAX;
		rep(j,0,k-1){
			int v=chosen[j];
			d=min(d,dis(i,v));
		}
		D=max(D,d);
	}
	return D;
}
void dfs(int u,int rest,int piece){
//	cout<<u<<endl;
	if(!rest){
		ans=min(ans,count());
		return;
	}
	vis[u]=true;
	int len=a[u].size();
	if(chose[f[u][0]]||(!chose[f[u][0]]&&piece>0)){
		chose[u]=true;
		rep(i,0,len-1){
			int v=a[u][i];
			if(vis[v])
				continue;
	//		chose[v]=false;
	//		dfs(v,rest,piece);
	//		chose[v]=true;
	//		if(chose[u]&&piece>0)
	//			dfs(v,rest-1,piece-1);
	//		else if(!chose[u])
	//			dfs(v,rest-1,piece  );
	//		chose[v]=false;
			if(!chose[f[u][0]]&&piece>0)
				dfs(v,rest-1,piece-1);
			else if(chose[f[u][0]])
				dfs(v,rest-1,piece);
		}
		chose[u]=false;
//		vis[u]=false;
	}
	chose[u]=false;
	rep(i,0,len-1){
		int v=a[u][i];
		if(vis[v])
			continue;
		dfs(v,rest,piece);
	}
	vis[u]=false;
}
void solve(){
	scanf("%d%d",&n,&k);
	lg=log2(n);
	rep(i,1,n){
		vis[i]=false;
		deep[i]=0;
		a[i].clear();
		rep(j,0,20)
			f[i][j]=false;
	}
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	init();
//	cout<<f[1][0]<<endl;
//	cout<<lca(10,6);
//	cout<<dis(5,9)<<endl;
	rep(i,1,n){
		chose[i]=false;
		vis[i]=false;
	}
//	vis[1]=true;
	dfs(1,k,2);
//	vis[1]=true;
//	chose[1]=true;
//	dfs(1,k-1,1);
//	rep(i,1,n){
//		chose[i]=false;
//		vis[i]=false;
//	}
//	vis[1]=true;
//	chose[1]=false;
//	dfs(1,k,2);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in" ,"r",stdin );
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 1
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
