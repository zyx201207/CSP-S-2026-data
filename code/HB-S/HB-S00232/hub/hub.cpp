#include<bits/stdc++.h>
using namespace std;
namespace std{
	using i64=long long;
	using u32=unsigned int;
	using u64=unsigned long long;
	using p32=pair<int,int>;
	using p64=pair<long long,long long>;
	#define all(x) (x).begin(),(x).end()
	#define one(x) (x).first
	#define two(x) (x).second
}
int n,m,CASE;
struct edge{int to,nxt;};
struct edge E[2000005];
int head[1000005],cntE;
void add(int x,int y){E[++cntE]=edge{y,head[x]};head[x]=cntE;}
int dis[2][1000005],vis[1000005];
bool dfs_0(int x,int T,int pre,vector<int> &v){
	v.push_back(x);
	if(x==T)	return true;
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to;
		if(y==pre)	continue;
		if(dfs_0(y,T,x,v))	return true;
	}
	v.pop_back();return false;
}
void dfs_1(int x,int T,int pre,int Id){
	dis[Id][x]=dis[Id][pre]+1;
	if(x==T)	return;
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to;
		if(y==pre)	continue;
		dfs_1(y,T,x,Id);
	}
}
int dep[1000005];
void dfs_2(int x,int pre){
	if(vis[x]==1){dep[x]=-0x3f3f3f3f;return;}
	for(int i=head[x];i;i=E[i].nxt){
		int y=E[i].to;
		if(y==pre)	continue;
		dfs_2(y,x);dep[x]=max(dep[x],dep[y]+1);
	}
}
int ask(int x,int y,int pre){
	vector<int> p;dfs_0(x,y,0,p);
	for(int i=1;i<=n;i++)
		{dep[i]=0;vis[i]=0;dis[0][i]=-1;dis[1][i]=-1;}
	for(int i=0;i<p.size();i++)	vis[p[i]]=(p[i]!=x&&p[i]!=y);
	dis[0][x]=0;dfs_1(p[1],y,x,0);
	dis[1][y]=0;dfs_1(p.end()[-2],x,y,1);
	dfs_2(x,0);dfs_2(y,0);
	for(int D=1;D<pre;D++){
		int sum=0,flag=0;
		for(int i=1;i<=n;i++)
			if(dis[0][i]>=0&&dis[1][i]>=0&&min(dis[0][i],dis[1][i])>D)
				{flag=1;break;}
		if(flag==1)	continue;
		for(int i=1;i<=n;i++)
			if((sum+=(dep[i]>=D||i==x||i==y))>m)
				{flag=1;break;}
		if(flag==0)	return D;
	}
	return pre;
}
bool solve(int x,int y,int D){
	vector<int> p;dfs_0(x,y,0,p);
	for(int i=1;i<=n;i++)
		{dep[i]=0;vis[i]=0;dis[0][i]=-1;dis[1][i]=-1;}
	for(int i=0;i<p.size();i++)	vis[p[i]]=(p[i]!=x&&p[i]!=y);
	dis[0][x]=0;dfs_1(p[1],y,x,0);
	dis[1][y]=0;dfs_1(p.end()[-2],x,y,1);
	for(int i=1;i<=n;i++)
		if(dis[0][i]>=0&&dis[1][i]>=0&&min(dis[0][i],dis[1][i])>D)
			return false;
	int sum=0;dfs_2(x,0);dfs_2(y,0);
	for(int i=1;i<=n;i++)
		sum+=(dep[i]>=D||i==x||i==y);
	return (sum<=m);
}
bool check(int D){
	for(int i=1;i<=n;i++)
		for(int j=(i+1);j<=n;j++)
			if(solve(i,j,D))
				return true;
	return false;
}
void work(){
	cin>>n>>m;cntE=0;
	for(int i=1;i<=n;i++)	head[i]=0;
	for(int i=2;i<=n;i++)
		{int x,y;cin>>x>>y;add(x,y);add(y,x);}
	if(n==m){cout<<0<<"\n";return;}
	int ans=n;
	for(int i=1;i<=n;i++)
		for(int j=(i+1);j<=n;j++)
			ans=min(ans,ask(i,j,ans));
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>CASE>>T;
	while(T--)	work();
	return 0;
}