#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
	char ch=gc();bool o=0;
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')o=1;
	for(x=0;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	if(o)x=-x;
}
constexpr int _=505,__=5e5+5;
int O,n,m,d,q,a[__];
std::vector<std::pair<int,int> >b[__];
long long f[_][_];
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
	fio("subway");
	rd(O),rd(n),rd(m),rd(d),rd(q);
	for(int i=1;i<=m;++i)rd(a[i]);
	for(int i=1;i<=n;++i){
		int k;rd(k);
		for(int x,y;k;--k){
			rd(x),rd(y);
			b[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)f[i][j]=f[j][i]=1e18;
	for(int u=1;u<=m;++u){
		for(auto pr1:b[u])for(auto pr2:b[u]){
			int i=pr1.first,j=pr2.first,w=pr1.second+pr2.second;
			f[j][i]=f[i][j]=std::min(f[i][j],0ll+w);
		}
	}
	// for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
	// 	printf("%d %d %lld\n",i,j,f[i][j]);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
	for(int u,v;q;--q){
		rd(u),rd(v);
		long long ans=1e18;
		for(auto pr1:b[u])for(auto pr2:b[v]){
			int i=pr1.first,j=pr2.first,w=pr1.second+pr2.second;
			ans=std::min(ans,f[i][j]+a[u]+a[v]+w);
		}
		printf("%lld\n",ans);
	}
}
// 15:29 15:38