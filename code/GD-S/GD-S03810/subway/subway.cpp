#include<bits/stdc++.h>
#define M(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> pll;
const long long inf=1e18;
const int N=5e2+10;
const int M=5e5+10;
int c,n,m,d,q,a[M],k[N];
long long f[N][N];
vector<pll> vec[M];
unordered_map<int,int> mp[N]; 
inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=(x*10)+(c-'0'),c=getchar();
	return x;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		a[i]=read();
	for(int i=1;i<=n;i++) {
		k[i]=read();
		for(int j=1;j<=k[i];j++) {
			int x,t;
			x=read(),t=read();
			mp[i][x]=t; 
			vec[x].push_back(M(i,t));
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<(int)vec[i].size();j++) {
			for(int k=j+1;k<(int)vec[i].size();k++) {
				int x=vec[i][j].first,y=vec[i][k].first;
				if(x!=y) {
					long long v=vec[i][j].second+vec[i][k].second;
					f[x][y]=min(f[x][y],v);
					f[y][x]=min(f[y][x],v);
				}
			} 
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=inf;
		for(int i=0;i<(int)vec[x].size();i++) {
			for(int j=0;j<(int)vec[y].size();j++) {
				int l=vec[x][i].first,r=vec[y][j].first;
				ans=min(f[l][r]+mp[l][x]+mp[r][y],ans);
			} 
		}
		ans+=a[x]+a[y];
		printf("%lld\n",ans);
	}
	return 0;
}
