#include<bits/stdc++.h>

#define ll long long
#define int ll
#define pii pair<int,int> 

using namespace std;

int read() {
	int x=0,f=1; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x*10)+(ch-'0');
	return x*f;
}

const int maxn = 505;
const int maxm = 500050;

int c,n,m,d,q;
int f[maxn][maxn];
int wast[maxm];
vector<pii> G[maxm];


signed main() {
	
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) wast[i]=read();
	memset(f,0x3f,sizeof(f)); for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=1;j<=k;j++) {
			int a=read(),t=read();
			G[a].push_back({i,t}); 
		}
	}
	for(int u=1;u<=m;u++) {
		if(!G[u].size()) continue;
		int sz=G[u].size(); sz--;
		for(int i=0;i<=sz;i++) {
			for(int j=i+1;j<=sz;j++) {
				int x=G[u][i].first,y=G[u][j].first;
				int val=G[u][i].second+G[u][j].second;
				f[x][y]=min(f[x][y],val); f[y][x]=min(f[y][x],val);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--) {
		int x=read(),y=read();
		int ans=1e18;
		for(auto qwq:G[x]) {
			for(auto uwu:G[y]) {
				int u=qwq.first,v=uwu.first;
				ans=min(ans,wast[x]+wast[y]+qwq.second+f[u][v]+uwu.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
gan jue bu ru yuan shen
*/
