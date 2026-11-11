#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
#define f(i,l,r) for(int i=l,R##R=r;i<=R##R;++i)
#define g(i,l,r) for(int i=l,R##R=r;i>=R##R;--i)
const int N=5e2+10,M=5e5+10,inf=1e18;
int C,n,m,q,x,y,z,as,d[N][N],w[M],c[M],a[M][21],t[M][21];
inline void cmn(int &x,int y){x>y&&(x=y);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	memset(d,0x3f,sizeof d);
	cin>>C>>n>>m>>x>>q;
	f(i,1,m) cin>>w[i];
	f(i,1,n){
		cin>>z;
		f(j,1,z) cin>>x>>y,a[x][++c[x]]=i,t[x][c[x]]=y;
	}
	f(i,1,m) f(j,1,c[i]) f(k,1,c[i]) cmn(d[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	f(i,1,n) d[i][i]=0;
	f(k,1,n) f(i,1,n) f(j,1,n) cmn(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		cin>>x>>y; as=inf;
		f(i,1,c[x]) f(j,1,c[y]) cmn(as,t[x][i]+t[y][j]+d[a[x][i]][a[y][j]]);
		cout<<as+w[x]+w[y]<<'\n';
	}
	return 0;
}
