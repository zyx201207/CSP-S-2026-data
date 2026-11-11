#include<bits/stdc++.h>
const int QWQ=2e6+5;
using namespace std;
using LL=long long;
template<typename T=int>
inline T read(){
	T x=0; int f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int Tp,T,n; LL d,a[QWQ],ans;
const int N=3e3+5;
int q[N],f[N]; LL g[N],sg;
const int N1=2e6+5;
int pr[QWQ];
inline void solve(){
	n=read(),d=read<LL>(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read<LL>();
	if (n==1){ puts("0"); return ; }
	if (11<=Tp&&Tp<=12){
		LL dc=a[2]-a[1]; d=min(d/dc,1ll*n);
		for (int i=1;i<d;i++){
			int t=(d+i)/2,r=d+i-t*2;
			pr[i]=pr[i-1]+(r==1&&t+2>d||t==1);
		}
		for (int i=1;i<=n;i++){
			int l=i+d,r=i+d+d;
			if (l>=n) break;
			ans+=pr[min(d-1,n-i-d)];
		}
		printf("%lld\n",ans);
		return ;
	}
	for (int i=1;i<=n;i++){
		int l=1,r=1,sgr=1; q[r]=i,f[i]=0,g[i]=1,sg=1;
		for (int j=i+1;j<=n;j++){
			for (;l<=r&&a[j]-a[q[l]]>d;l++) sg-=g[q[l]];
			if (l>r) break;
			for (;sgr<r&&f[q[l]]==f[q[sgr+1]];) sgr++,sg+=g[q[sgr]];
			ans+=sg==2,f[j]=f[q[l]]+1,g[j]=sg,q[++r]=j;
			if (g[q[l]]>1000) break;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for (Tp=read(),T=read();T--;) solve();
	return 0;
}
