#include <cstdio>
#include <queue>
#define re register
typedef long long LL;
inline LL read() {
	re bool f=true; re LL x=0; re char c;
	while((c=getchar())<'0') if(c=='-') f=false;
	do x=(x<<1)+(x<<3)+(c^48); while((c=getchar())>'-');
	return f?x:~x+1;
}
const int N=2e6+6;
LL x[N];
int cntL[N],cntR[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	short c; int t; scanf("%hd%d",&c,&t);
	while(t--) {
		int n; scanf("%d",&n); LL d=read();
		std::queue<int> qL,qR;
		for(re int i=0;i!=n;x[++i]=read());
		*x=1[x]-d-33,x[n+1]=x[n]+d+33;
		for(re int i=1,j=1,tot=0;i<=n;++i) {
			while(!qL.empty() && x[qL.front()]+d<x[i]) --tot,qL.pop();
			if(x[j]+d>=x[i])
				while(j!=i && x[j]+d<x[i+1]) ++tot,qL.push(j++);
			cntL[i]=tot+1;
		}
		for(re int i=n,j=n,tot=0;i;--i) {
			while(!qR.empty() && x[qR.front()]-d>x[i]) --tot,qR.pop();
			if(x[j]-d<=x[i])
				while(j!=i && x[j]-d>x[i-1]) ++tot,qR.push(j--);
			cntR[i]=tot+1;
		}
		LL ans=0;
		for(re int i=2;i+1<=n;++i)
			if(x[i-1]+d>=x[i+1] && x[i-1]+d<x[i+2] && x[i+2]-d<=x[i] && x[i+2]-d>x[i-1])
				ans+=cntL[i-1]*1ll*cntR[i+2];
		printf("%lld\n",ans);
	}
	return 0;
}
// Code by 33
