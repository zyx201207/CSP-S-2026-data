#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=2e6+5;
const LL INF=1e18+5;
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
int n;
LL d,x[N];
void init(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
}
LL dis[N],f[N];
void solven(){
	LL ans=0;
	for(int u=1;u<=n;u++){
		for(int v=u;v<=n;v++) dis[v]=n+1,f[v]=0;
		dis[u]=0,f[u]=1;
		for(int v=u+1;v<=n;v++){
			int p=lower_bound(x+1,x+n+1,x[v]-d)-x;
			for(int i=max(u,p);i<v;i++){
				if(dis[i]+1<dis[v]) dis[v]=dis[i]+1,f[v]=f[i];
				else if(dis[i]+1==dis[v]) f[v]+=f[i];
			}
			if(f[v]==2) ans++;
		}
	}
	printf("%lld\n",ans);
}
void solveA(){
	LL k=x[2]-x[1];
	LL len=d/k;
	if(len<=1){
		puts("0");
		return;
	}
	len+=len-1;
	LL ans=n-len;
	printf("%lld\n",max(0ll,ans));
}
void solveB(){
	LL ans=0;
	x[0]=-INF,x[n+1]=INF;
	for(int i=1;i<n;i++){
		int pl=upper_bound(x+1,x+n+1,x[i-1]+d)-x;
		int pr=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		int c0=max(0,pr-pl+1);
		pl=lower_bound(x+1,x+n+1,x[i+1]-d)-x;
		pr=lower_bound(x+1,x+n+1,x[i+2]-d)-x-1;
		int c1=max(0,pr-pl+1);
		ans+=1ll*c0*c1;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		init();
		if(c==11||c==12) solveA();
		else if(c==13||c==14) solveB();
		else solven();
	}
	return 0;
}
