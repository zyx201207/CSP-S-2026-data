#include<bits/stdc++.h>
#define N 100010
using namespace std;
int c,T,n,k,dep[N],h[20][N],f[N];
int len[15][15],fth[N],uva[N],ans;
vector<int>v[N];
pair<int,int>e[N];
void dfs(int u,int fa){
	h[0][u]=fa,dep[u]=dep[fa]+1;
	for(int i=0;i<(int)v[u].size();i++){
		int t=v[u][i];
		if(t==fa){
			continue;
		}
		dfs(t,u);
	}
}
int LCA(int x,int y){
	if(dep[x]>dep[y]){
		swap(x,y);
	}
	for(int i=18;i>=0;i--){
		if(dep[h[i][y]]>=dep[x]){
			y=h[i][y];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=18;i>=0;i--){
		if(h[i][x]!=h[i][y]){
			x=h[i][x],y=h[i][y];
		}
	}
	return h[0][x];
}
int getfa(int x){
	if(fth[x]==x){
		return x;
	}
	return fth[x]=getfa(fth[x]);
}
void merge(int x,int y){
	x=getfa(x),y=getfa(y);
	fth[x]=y;
}
void solve(int u,int cnt){
	if(u>n){
		if(cnt!=k){
			return;
		}
		for(int i=1;i<=n;i++){
			fth[i]=i;
		}
		for(int i=1;i<n;i++){
			int x=e[i].first,y=e[i].second;
			if(f[x]&&f[y]){
				merge(x,y);
			}
		}
		memset(uva,0,sizeof(uva));
		for(int i=1;i<=n;i++){
			if(f[i]){
				uva[getfa(i)]=1;
			}
		}
		int cyy=0;
		for(int i=1;i<=n;i++){
			cyy+=uva[i];
		}
		if(cyy>2){
			return;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			int now=N;
			for(int j=1;j<=n;j++){
				if(f[j]){
					now=min(now,len[i][j]);
				}
			}
			res=max(res,now);
		}
		ans=min(ans,res);
		return;
	}
	f[u]=0;
	solve(u+1,cnt);
	f[u]=1;
	solve(u+1,cnt+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[i]=make_pair(x,y);
			v[x].push_back(y),v[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=18;i++){
			for(int j=1;j<=n;j++){
				h[i][j]=h[i-1][h[i-1][j]];
			}
		}
		if(n<=10){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					len[i][j]=dep[i]+dep[j]-2*dep[LCA(i,j)];
				}
			}
			ans=N;
			solve(1,0);
			cout<<ans<<"\n";
			continue;
		}
		//k=2
	}
	return 0;
}