#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct edge{
	int to,nxt;
}e[maxn];
int n,m,head[maxn],cnt,dep[maxn],lca[1005][1005],dis[1005][1005],fa[maxn],zf[maxn],ans;
void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void Dfs(int x,int f){
	zf[x]=f;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==f)continue;
		Dfs(e[i].to,x);
	}
}
int getlca(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y])swap(x,y);
		x=zf[x];
	}
	return x;
}
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)head[i]=0;
	cnt=0;
	ans=1e9;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	Dfs(1,0);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)lca[i][j]=getlca(i,j),dis[i][j]=dep[i]+dep[j]-2*dep[lca[i][j]];
	for(int k=0;k<(1<<n);k++){
		if(__builtin_popcount(k)!=m)continue;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			if(!((k>>i-1)&1))continue;
			for(int j=head[i];j;j=e[j].nxt){
				if(!((k>>e[j].to-1)&1))continue;
				fa[find(i)]=find(e[j].to);
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!((k>>i-1)&1))continue;
			tot+=(find(i)==i);
		}
		if(tot>2)continue;
//		cerr<<"out:";
//		for(int i=1;i<=n;i++){
//			if(!((k>>i-1)&1))continue;
//			cerr<<i<<" ";
//		}
//		cerr<<"\n";
		int res=0;
		for(int i=1;i<=n;i++){
			int tmp=1e9;
			for(int j=1;j<=n;j++){
				if(!((k>>j-1)&1))continue;
//				cerr<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
				tmp=min(tmp,dis[i][j]);
			}
			res=max(res,tmp);
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
//	exit(0);
}
//dp[i][j]->i号点，最近的点距离为j ，选了k个点的最短距离。
bitset<1005>bit[1005];
bool check(int x){
	for(int i=1;i<=n;i++)bit[i].reset();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=x)bit[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bitset<1005>tmp=bit[i]|bit[j];
			if(tmp.count()==n)return 1;
		}
	}
	return 0;
}
void solve2(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)head[i]=0;
	cnt=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	Dfs(1,0);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)lca[i][j]=getlca(i,j),dis[i][j]=dep[i]+dep[j]-2*dep[lca[i][j]];
	int l=0,r=n,mid;
	while(l<r){
		mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _,__;
	cin>>_>>__;
	if(_<=3)while(__--)solve1();
	else while(__--)solve2();
	return 0;
}

