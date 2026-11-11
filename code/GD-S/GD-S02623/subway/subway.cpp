#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
inline int in() {
	static char ch;
	static int a,f;
	ch=getchar();
	a=0,f=1;
	for(; !isdigit(ch); ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch); ch=getchar())a=(a<<1)+(a<<3)+ch-'0';
	return a*f;
}
const int C=5e5+120,S=600;
const long long INF=1e18;
int c,n,m,q1,q;
int w[C];
vector<int> a[S],t[S];
int c_t[C][21],c_l[C][21];
long long d[S][S];
inline void init() {
	memset(d,0x3f,sizeof(d));
	c=in();
	n=in();
	m=in();
	q1=in();
	q=in();
	int i,j,tmp;
	for(i=1; i<=m; i++)w[i]=in();
	for(i=1; i<=n; i++) {
		tmp=in();
		a[i].resize(tmp+2);
		t[i].resize(tmp+2);
		a[i][0]=t[i][0]=tmp;
		for(j=1;j<=tmp;j++){
			a[i][j]=in();
			t[i][j]=in();
			c_t[a[i][j]][++c_t[a[i][j]][0]]=i;
			c_l[a[i][j]][++c_l[a[i][j]][0]]=t[i][j];
		}
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	int i,j,k;
	for( i=1;i<=m;i++){//5e5
		for( j=2;j<=c_t[i][0];j++){//20
			for( k=1;k<j;k++){//20
				d[c_t[i][k]][c_t[i][j]]=d[c_t[i][j]][c_t[i][k]]=min(d[c_t[i][j]][c_t[i][k]],(long long)(c_l[i][j]+c_l[i][k]));
			}
		}
	}
	for( i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){d[i][j]=0;break;}
			for(k=1;k<=n;k++){
				d[j][i]=d[i][j]=min(d[i][j],d[i][k]+d[j][k]);
			}
		}
	}
	int u,v;
	long long cgs;
	for(i=1;i<=q;i++){
		cgs=INF;
		u=in();v=in();
		for(j=1;j<=c_t[u][0];j++)//c_t[u][j]
			for(k=1;k<=c_t[v][0];k++){//c_t[v][k]
				cgs=min(cgs,d[c_t[u][j]][c_t[v][k]]+c_l[u][j]+c_l[v][k]);
			}
		printf("%lld\n",cgs+w[u]+w[v]);
	}
	return 0;
}
