#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x;
	cin>>x;
	return x;
}
const int N=510,M=500010,D=30,INF=1000000000000000000;
int w[M],k[N],id[M][D],t[M][D],cnt[M],e[N][N];
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	int n=read();
	int m=read();
	read();
	int q=read();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			e[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++) {
		w[i]=read();
	}
	for(int i=1;i<=n;i++) {
		k[i]=read();
		for(int j=1;j<=k[i];j++) {
			int a=read();
			cnt[a]++;
			id[a][cnt[a]]=i;
			t[a][cnt[a]]=read();
		}
	}
	for(int i=1;i<=m;i++) {
		for(int x=1;x<=cnt[i];x++) {
			for(int y=1;y<=cnt[i];y++) {
				e[id[i][x]][id[i][y]]=min(e[id[i][x]][id[i][y]],t[i][x]+t[i][y]);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		e[i][i]=0;
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	for(int r=1;r<=q;r++) {
		int x=read(),y=read();
		int ans=INF;
		for(int i=1;i<=cnt[x];i++) {
			for(int j=1;j<=cnt[y];j++) {
				ans=min(ans,w[x]+t[x][i]+e[id[x][i]][id[y][j]]+t[y][j]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
