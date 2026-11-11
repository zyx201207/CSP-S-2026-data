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
constexpr int _=2e6+5;
int O;
long long d,a[_];
int n,b[_],c[_],e[5005][5005],f[_];
long long calc(){
	for(int i=1,j=1;i<=n;++i){
		for(;j<=n&&a[j]-a[i]<=d;++j);
		b[i]=j-1;
	}
	for(int i=n,j=n;i;--i){
		for(;j&&a[i]-a[j]<=d;--j);
		c[i]=j+1;
	}
	for(int i=1;i<=n;++i){
		e[i][i]=0;
		for(int j=i+1;j<=b[i];++j)e[i][j]=1;
		for(int j=b[i]+1;j<=n;++j)e[i][j]=e[i][c[j]]+1;
	}
	// for(int i=1;i<=n;++i)printf("%d %d %d\n",i,b[i],c[i]);
	long long val=0;
	for(int u=1;u<n;++u)for(int v=u+1;v<=n;++v){
		int cnt=0;
		for(int i=u+1;i<v;++i){
			cnt+=e[u][i]+e[i][v]==e[u][v];
			if(cnt>e[u][v])break;
		}
		// printf("%d %d %d\n",u,v,cnt);
		val+=cnt==e[u][v];
		for(int i=u+1;i<v;++i)f[e[u][i]]=0;
	}
	return val;
}
long long calc2(){
	for(int i=1,j=1;i<=n;++i){
		for(;j<=n&&a[j]-a[i]<=d;++j);
		b[i]=j-1;
	}
	for(int i=n,j=n;i;--i){
		for(;j&&a[i]-a[j]<=d;--j);
		c[i]=j+1;
	}
	int p=0;
	for(int i=1;i<=n;++i)if(b[i]==n&&c[i]==1){
		p=i;break;
	}
	long long val=0;
	int vl=0,vr=0;
	for(int i=1;i<=n;++i)vl+=b[i]==p,vr+=c[i]==p-1;
	val+=1ll*vl*vr;
	// printf("%d\n",p);
	// printf("%d %d\n",vl,vr);
	vl=vr=0;
	for(int i=1;i<=n;++i)vl+=b[i]==p+1,vr+=c[i]==p;
	val+=1ll*vl*vr;
	// printf("%d %d\n",vl,vr);
	return val;
}
int N;long long A[_];
void Diving1(){
	rd(N),rd(d);
	for(int i=1;i<=N;++i)rd(A[i]);
	// printf("%d %lld\n",N,d);
	if(A[1]+d>=A[N])return printf("0\n"),void();
	if(O==11||O==12){
		d/=A[2]-A[1];
		// printf("%d %lld\n",N,d);
		if(d<2)printf("0\n");
		else printf("%lld\n",N-d-d+1);
		return;
	}
	if(O==13||O==14){
		for(int i=1;i<=N;++i)a[i]=A[i];
		n=N;
		printf("%lld\n",calc2());
		return;
	}
	long long ans=0;int p=1;
	for(int i=2;i<=N;++i)if(A[i-1]+d<A[i]){
		n=0;for(int j=p;j<i;++j)a[++n]=A[j];
		ans+=calc();p=i;
	}
	n=0;for(int j=p;j<=N;++j)a[++n]=A[j];
	ans+=calc();
	printf("%lld\n",ans);
}
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
	fio("migrate");
	int T;rd(O),rd(T);
	for(;T;--T)Diving1();
}