#include<cstdio>
#include<algorithm>
typedef long long LL;
const int N=5e5+10;
LL n,m;
int ans;
LL a[N];
LL s[N];
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
inline LL delta(int i,int j){
	return /*printf("%d %d %d\n",i,j,a[i]*(i-j+1)-(s[i]-s[j-1])),*/a[i]*(i-j+1)-(s[i]-s[j-1]);
}
inline int solve(int i){
	int l=1,r=i,mid=0,ans=i;
	while(l<=r)delta(i,mid=l+r>>1)<=m?r=mid-1,ans=mid:l=mid+1;
//	printf("%d %d\n",i,ans);
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i)
		ans=std::max(ans,i-solve(i)+1);
	printf("%d\n",ans);
	return 0;
}
/*
14:44 O(n log n) 100 pts
*/
