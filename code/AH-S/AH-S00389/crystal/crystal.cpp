#include <cstdio>
#include <algorithm>
#define re register
typedef long long LL;
inline void read(LL &x) {
	re bool f=false; re char c;
	while((c=getchar())<'0') if(c=='-') f=true;
	do x=(x<<1)+(x<<3)+(c^48); while((c=getchar())>'-');
	if(f) x=~x+1;
}
const int N=5e5+5;
int n;
LL m,a[N],p[N];
bool check(int len) {
	for(re int i=len;i<=n;++i)
		if(p[i]-p[i-len]+m>=a[i]*len) return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(re int i=0;i!=n;read(a[++i]));
	std::sort(a+1,a+n+1);
	for(re int i=0;i++!=n;) p[i]=p[i-1]+a[i];
	int l=1,r=n;
	while(l!=r) {
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
