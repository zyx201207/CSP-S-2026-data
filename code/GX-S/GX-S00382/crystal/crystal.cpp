#include<cstdio>
#include<algorithm>
using namespace std;
#define qwq Ff472130
#define ll long long
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
constexpr int N=5e5+10;
constexpr int inf=1e9+10;

inline void read(ll &x) {
	x=0;int f=1;
	char ch=getchar();
	while (ch<48) {if(ch=='-')f=-1;ch=getchar();}
	while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;
}

int n;
ll a[N],s[N],m;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%d",&n);read(m);
	f(i,1,n) read(a[i]);
	sort(a+1,a+1+n);
	f(i,1,n) s[i]=s[i-1]+a[i];
	int ans=0;
	f(i,1,n) {
		int l=1,r=i,res=-1;
		while (l<=r) {
			int mid=l+r>>1;
			ll val=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if (val<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	printf("%d\n",ans);
	return 0;
}

/*
AC:14:42
qwq
*/
