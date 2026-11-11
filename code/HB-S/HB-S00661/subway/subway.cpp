#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N=505,M=5e5+5;
const LL INF=1e18;
inline LL read(){
	LL res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	if(f==1) return res;
	return -res;
}
int c,n,m,d,q,w[M],k[N];
vector<PII> pt[N];
vector<PII> ps[M];
LL f[N][N];
void init(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=0;j<k[i];j++){
			int a=read(),t=read();
			PII cur;cur.first=a,cur.second=t;
			pt[i].push_back(cur);
			cur.first=i,cur.second=j;
			ps[a].push_back(cur);
		}
	}
}
void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=INF;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int sz=ps[i].size();
		for(int x=0;x<sz;x++){
			int p1=ps[i][x].first,j1=ps[i][x].second;
			for(int y=0;y<sz;y++){
				int p2=ps[i][y].first,j2=ps[i][y].second;
				LL w=0ll+pt[p1][j1].second+pt[p2][j2].second;
				f[p1][p2]=min(f[p1][p2],w);
				f[p2][p1]=f[p1][p2];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
}
void solve(){
	int x=read(),y=read();
	LL ans=INF;
	for(int a=0;a<(int)ps[x].size();a++){
		for(int b=0;b<(int)ps[y].size();b++){
			int p1=ps[x][a].first,j1=ps[x][a].second;
			int p2=ps[y][b].first,j2=ps[y][b].second;
			LL res=0ll+w[x]+w[y]+pt[p1][j1].second+pt[p2][j2].second+f[p1][p2];
			if(ans>res) ans=res;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	build();
	while(q--) solve();
	return 0;
}


