#include<bits/stdc++.h>

using namespace std;

int c,T,n,k,A[15][15],flag[15],vis[15],ans,father[1000005][20],dep[1000005],id,Id,lsh[1000005],m;
vector<int>E[1000005];
void dfs(int x) {
	vis[x]=1;
	for(int i=1;i<=n;i++) if(!vis[i]&&flag[i]&&A[x][i]==1) dfs(i); 
}
int calc() {
	int ans=0;
	for(int i=1;i<=n;i++) {
		int minn=1e9;
		for(int j=1;j<=n;j++) if(flag[j]) minn=min(minn,A[i][j]);
		ans=max(ans,minn);
	}
	return ans;
}
void Dfs(int x,int fa) {
	father[x][0]=fa,dep[x]=dep[fa]+1;
	for(int i=1;i<=19;i++) father[x][i]=father[father[x][i-1]][i-1];
	for(auto v:E[x]) if(v!=fa) Dfs(v,x);
}
int LCA(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[x]-dep[y]>=(1<<i)) x=father[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(father[x][i]!=father[y][i]) x=father[x][i],y=father[y][i];
	return father[x][0];
}
int dist(int x,int y) {
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int solve(int x) {
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dist(x,i));
	return ans;
}
int solve(int x,int y) {
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,min(dist(x,i),dist(y,i)));
	return ans;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14) {
		while(T--) {
			cin>>n>>k;
			for(int i=1;i<n;i++) {
				int x,y;
				cin>>x>>y;
			}
			if(k==n) cout<<"0\n";
			else if(k==1) cout<<((n+1)/2+1)/2<<"\n";
			else cout<<max(1,((n+1)/2-(k-2)+3)/4)<<"\n";
		}
		return 0;
	}
	if(c<=3) {
		while(T--) {
			cin>>n>>k,ans=1e9;
			memset(A,0x3f,sizeof A);
			for(int i=1;i<=n;i++) A[i][i]=0,E[i].clear();
			for(int i=1;i<n;i++) {
				int x,y;
				cin>>x>>y,A[x][y]=A[y][x]=1,E[x].push_back(y),E[y].push_back(x);
			}
			for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
			for(int i=0;i<(1<<n);i++) if(__builtin_popcount(i)==k) {
				for(int j=1;j<=n;j++) flag[j]=((i>>(j-1))&1),vis[j]=0;
				int cnt=0;
				for(int j=1;j<=n;j++) if(flag[j]&&!vis[j]) dfs(j),cnt++;
				if(cnt<=2) ans=min(ans,calc());
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(c==7||c==11||c==12) {
		while(T--) {
			cin>>n>>k,m=0,ans=1e9;
			for(int i=1;i<=n;i++) E[i].clear();
			for(int i=1;i<n;i++) {
				int x,y;
				cin>>x>>y,E[x].push_back(y),E[y].push_back(x);
			}
			Dfs(1,0);
			for(int i=1;i<=n;i++) if(dep[i]>dep[id]) id=i;
			Dfs(id,0);
			for(int i=1;i<=n;i++) if(dep[i]>dep[Id]) Id=i;
			lsh[++m]=Id;
			while(Id!=id) Id=father[Id][0],lsh[++m]=Id;
			if(k==1) {
				cout<<min(solve(lsh[m/2]),solve(lsh[(m+1)/2]))<<"\n";
				continue;
			}
			int l=1,r=m/2;
			while(r-l>5) {
				int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
				if(solve(lsh[lmid],lsh[m-lmid+1])>solve(lsh[rmid],lsh[m-rmid+1])) l=lmid;
				else r=rmid;
			}
			for(int i=l;i<=r;i++) ans=min(ans,solve(lsh[i],lsh[m-i+1]));
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
