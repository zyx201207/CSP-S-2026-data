#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=21;
int c,t,n,m,head[N],to[N<<1],nex[N<<1],cnt,dep[N],f[N][M],ans,tot;
bool box[N],vis[N];
inline void add(int x,int y){
	nex[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
}
void dfs(int now,int fa){
	dep[now]=dep[fa]+1,f[now][0]=fa;
	for(int i=1;i<M;i++) f[now][i]=f[f[now][i-1]][i-1];
	for(int i=head[now];i;i=nex[i]){
		int r=to[i];
		if(r!=fa) dfs(r,now);
	}
}
void dfs2(int now){
	vis[now]=true;
	for(int i=head[now];i;i=nex[i]){
		int r=to[i];
		if(!box[r]||vis[r]) continue;
		dfs2(r);
	}
}
bool check(){
	tot=0;
	for(int i=1;i<=n;i++) vis[i]=false;
	for(int i=1;i<=n;i++){
		if(!box[i]||vis[i]) continue;
		tot++;
		if(tot>2) return false;
		dfs2(i);
	}
	return true;
}
int find(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int delt=dep[x]-dep[y],s=0;
	while(delt){
		if(delt&1) x=f[x][s];
		s++;
		delt>>=1;
	}
	if(x==y) return x;
	for(int i=M-1;i>=0;i--){
		if(f[x][i]==f[y][i]) continue;
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
void cal(){
	vector<int> lis;
	for(int i=1;i<=n;i++){
		if(box[i]) lis.push_back(i);
	}
	int siz=lis.size(),res=0;
	for(int i=1;i<=n;i++){
		if(box[i]) continue;
		int tmp=n+1;
		for(int j=0;j<siz;j++){
			int lca=find(i,lis[j]);
			tmp=min(tmp,dep[i]+dep[lis[j]]-(dep[lca]<<1));
		}
		res=max(res,tmp);
	}
	ans=min(ans,res);
}
void getxl(int now,int sum){
	if(now==n){
		if(sum<m) return;
		if(check()) cal();
		return;
	}
	box[now+1]=false;
	getxl(now+1,sum);
	if(sum<m){
		box[now+1]=true;
		getxl(now+1,sum+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;i++){
			dep[i]=-1;
			for(int j=0;(1<<j)<=n;j++) f[i][j]=0;
		}
		dfs(1,0);
		ans=N;
		for(int i=1;i<=n;i++) box[i]=false;
		getxl(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
