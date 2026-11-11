#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void dd(int &x){
	x=0;
	char ch=getchar();int ff=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0',ch=getchar();
	}
	x*=ff;
}
const int N=505,M=5e5+5;
const ll inf=1e18;
ll f[N][N];
int n,m,d,q,w[M],num[M],a[M][25],t[M][25];
void cmin(ll &x,ll y){
	x=x<y?x:y;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	dd(n),dd(n),dd(m),dd(d),dd(q);
	for(int i=1;i<=m;++i) dd(w[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[i][j]=inf;
	for(int i=1,k;i<=n;++i){
		dd(k);
		f[i][i]=0;
		for(int j=1,x,y;j<=k;++j){
			dd(x),dd(y);
			t[x][++num[x]]=y;
			a[x][num[x]]=i;
		}
	}
	for(int k=1;k<=m;++k){
		for(int i=1;i<=num[k];++i){
			for(int j=i+1;j<=num[k];++j){
				cmin(f[a[k][i]][a[k][j]],t[k][i]+t[k][j]);
				f[a[k][j]][a[k][i]]=f[a[k][i]][a[k][j]];
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cmin(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int TT=1,x,y;TT<=q;++TT){
		dd(x),dd(y);
		ll ans=inf;
		for(int i=1;i<=num[x];++i){
			for(int j=1;j<=num[y];++j){
				cmin(ans,f[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
}
