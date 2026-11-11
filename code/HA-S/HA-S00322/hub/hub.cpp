#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
typedef long long ll;
const int N=505;

inline ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,k,ans,cnt,dis[N][N],d[N];
bool vis[N];
vector<int> kk[N];

void dfs2(int x,int fa) {
	if(vis[x]) {
		if(!vis[fa]) cnt++;
	}
	for(int y:kk[x]) {
		if(y==fa) continue;
		dfs2(y,x);
	}
}

void check() {
	int num=0;
	for(int i=1;i<=n;i++) num+=vis[i];
	if(num!=k) return;
	cnt=0;
	dfs2(1,0);
	if(cnt>2) return;
	
	vector<int> tmp;
	for(int i=1;i<=n;i++) if(vis[i]) tmp.push_back(i);
	for(int i=1;i<=n;i++) {
		d[i]=0x3f3f3f3f3f3f3f3f;
		for(int j:tmp) {
			d[i]=min(d[i],dis[i][j]);
		}
	}
	
	int maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,d[i]);
	ans=min(ans,maxx);
}

void dfs(int num) {
	if(num>n) {
		check();
		return;
	}
	vis[num]=0,dfs(num+1);
	vis[num]=1,dfs(num+1);
}

void work() {
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++) kk[i].clear();
	for(int i=1;i<n;i++) {
		int x=read(),y=read();
		kk[x].push_back(y);
		kk[y].push_back(x);
		dis[x][y]=dis[y][x]=min(dis[x][y],1ll);
	}
	
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	ans=0x3f3f3f3f3f3f3f3f;
	dfs(1);
	printf("%lld\n",ans);
}

signed main() {
	 freopen("hub.in","r",stdin);
	 freopen("hub.out","w",stdout);
	
	int c=read(),t=read();
	while(t--) work();	
	return 0;
}
// Oct31==Dec25?
