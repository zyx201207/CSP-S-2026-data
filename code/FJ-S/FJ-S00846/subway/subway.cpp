#include<cstdio>
#include<cstring>
#include<vector>
#define N 505
#define M 500005
using namespace std;

using ll=long long;
inline void getmin(ll &x,ll y) {x=min(x,y);}
ll read() {
	ll x=0,t=1; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*t;
}
void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int n,m,d,q,w[M];
ll f[N][N];
vector<int> a[M],t[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		int k=read();
		for(int j=0,x,y;j<k;j++) x=read(),y=read(),a[x].push_back(i),t[x].push_back(y);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(int u=0;u<(int)a[i].size();u++) {
			for(int v=0;v<(int)a[i].size();v++) {
				if(u!=v) getmin(f[a[i][u]][a[i][v]],t[i][u]+t[i][v]);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) getmin(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;i++) {
		int x=read(),y=read(); ll ans=0x3f3f3f3f3f3f3f3f;
		for(int u=0;u<(int)a[x].size();u++) {
			for(int v=0;v<(int)a[y].size();v++) {
				getmin(ans,t[x][u]+f[a[x][u]][a[y][v]]+t[y][v]);
			}
		}
		write(w[x]+ans+w[y]),putchar('\n');
	}
	return 0;
}

/*
check if <vector> <cmath> is open

check long long
check memory limit

把线路视为点，则有 n^2 条边，处理时间 \sum k_i*d = O(md) 
跑一遍 floyd，时间 O(n^3) 
对于每次询问，枚举两条地铁线，时间 O(qd^2) 
最后加上两个地铁站的 w_v 
O(md+n^3+qd^2) = 175,000,000 预期可过 

15:09
*/
