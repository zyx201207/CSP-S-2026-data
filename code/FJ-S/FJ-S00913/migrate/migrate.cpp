#include<cstdio>
typedef long long LL;
const int N=2e6+10;
int c,T,n;
LL d,ans;
LL a[N];
LL nxt[N],lst[N];
//LL s[N];
LL f[N],g[N];
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
//inline int Find(int i){
//	int l=i,r=n,mid=0,ans=i;
//	while(l<=r)a[mid=l+r>>1]-a[i]<=d?l=mid+1,ans=mid:r=mid-1;
//	return ans;
//}
//inline int FindL(int i){
//	int l=1,r=i,mid=0,ans=i;
//	while(l<=r)a[i]-a[mid=l+r>>1]<=d?r=mid-1,ans=mid:l=mid+1;
//	return ans;
//}
inline void solve(){
	n=read(),d=read(),ans=0;
	for(int i=1;i<=n;++i)
		a[i]=read(),f[i]=0,g[i]=0;
	a[n+1]=a[n]+d+1,a[0]=a[1]-d-1;
	for(int i=1,l=1;i<=n+1;++i)while(l<i&&a[i]-a[l]>d)
		nxt[l]=i-1,++l;
	for(int i=n,r=n;i>=0;--i)while(r>i&&a[r]-a[i]>d)
		lst[r]=i+1,--r;
//	for(int i=1;i<=n;++i)
//		nxt[i]=Find(i),lst[i]=FindL(i);
//	for(int i=1;i<=n;++i)
//		s[i]=s[i-1]+nxt[i];
//	for(int i=2;i<=n;++i)
//		d[i]=Find(i)-Find(i-1);
	for(int i=n;i>1;--i)//ji de chu shi hua f[] u -> (i-1 X),i -> v
		f[i]=(nxt[i]>nxt[i-1]?f[nxt[i]]:0)+nxt[i]-nxt[i-1];
	for(int i=1;i<n;++i)//v <- i,(i+1 X) <- u
		g[i]=(lst[i+1]>lst[i]?g[lst[i]]:0)+lst[i+1]-lst[i];
	for(int i=1,t,l,r;i<=n;++i){
		if((t=nxt[i])-i<2)continue;
		l=(t-2==i?t:nxt[t-2])+1,r=nxt[t-1];
		if(l>r)continue;
		ans+=(lst[t-1]==i?g[i]+1:1)*(nxt[t]==r?f[r]+(r-l+1):(r-l+1));
//		printf("%d %d %d %lld %lld\n",i,l,r,(lst[t-1]==i?g[t]+1:1),nxt[t]==r?f[r]+(r-l+1):(r-l+1));
		//last (is t)
//		ll=FindL(i),lr=FindL(t-1)-1,rl=Find(t)+1;//printf("%d %d\n",ll,lr);
//		ans+=(s[r]-s[l-1]-1LL*(r-l+1)*(rl-1)+1)*(lr>=ll?lr-ll+1+1:1);
//		printf("%d %d %lld %lld\n",l,r,s[r]-s[l-1],1LL*(r-l+1)*(rl-1));
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
/*
15:50 O(n^2 log n) 40 pts(idea) X
15:54 O(3n log n) 100? pts(idea) X(pre idea)
17:39 O(n log n) 100? pts
17:45 O(n) 100 pts
*/
