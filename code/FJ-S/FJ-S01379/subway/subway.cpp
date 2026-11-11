#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
const int N=510,M=5e5+10;
int n,m,d,q,w[M],f[N][N];
#define pii pair<int,int>
vector<pii>g[M];//id shijian
void print(int x){if (x>9) print(x/10);putchar(x%10^48);} 
main(){
//	system("fc subway.out subway3.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=1e18;
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read(),y=read();
			g[x].push_back({i,y});
		}
	}
	int cnt=0;
	for (int i=1;i<=m;i++){
		int len=g[i].size();
		for (int x=0;x<len;x++) for (int y=x+1;y<len;y++){
			int idx=g[i][x].first,idy=g[i][y].first;
			f[idx][idy]=min(f[idx][idy],g[i][x].second+g[i][y].second);
			f[idy][idx]=min(f[idy][idx],g[i][x].second+g[i][y].second);
		}
		cnt+=len*len;
	}
//	cerr <<cnt<<endl;
	for (int k=1;k<=n;k++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	cout <<f[2][2]<<endl;
	while(q--){
		int x=read(),y=read();
		int ans=1e18;
		int lenx=g[x].size(),leny=g[y].size();
		for (int i=0;i<lenx;i++) for (int j=0;j<leny;j++){
			int idx=g[x][i].first,idy=g[y][j].first;
//			cout <<idx<<" "<<idy<<" "<<f[idx][idy]+g[x][i].second+g[y][j].second<<endl;
			ans=min(ans,f[idx][idy]+g[x][i].second+g[y][j].second);
		}
		print(ans+w[x]+w[y]),putchar(10);
	}
	cerr<<(double)clock()/CLOCKS_PER_SEC<<endl; 
	return 0;
}

