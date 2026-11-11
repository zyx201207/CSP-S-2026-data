#include <bits/stdc++.h>
using namespace std;

char buf[1<<21], *p1, *p2;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf, 1, 1<<21, stdin), p1==p2)?EOF:*p1++)

template <typename T>
inline void Read(T &in){
	in=0;
	bool tag=0;
	char ch=0;
	while (ch=getchar(), !isdigit(ch) && ch!=EOF) if (ch=='-') tag=1;
	if (ch==EOF) return;
	while (isdigit(ch)) in=(in<<1)+(in<<3)+ch-48, ch=getchar();
	if (tag) in=-in;
	return;
}

template <typename T, typename ...Args>
inline void Read(T &in, Args &...rest){
	return Read(in), Read(rest...);
}

using ll=long long;
#define MAXN 500005

namespace akakakak{

	int n, l, r, ans;
	ll m, a[MAXN];

	inline bool Check(int x){
		for (int i=x;i<=n;++i) if ((a[i]-a[i-1])*x-(a[i]-a[i-x])<=m) return 1;
		return 0;
	}

	inline int main(){
		Read (n, m);
		for (int i=1;i<=n;++i) Read (a[i]);
		sort (a+1, a+n+1);
		for (int i=2;i<=n;++i) a[i]+=a[i-1];
		l=1, r=n, ans=l;
		while (l<=r){
			int mid=(l+r)>>1;
			if (Check(mid)){
				ans=max(ans, mid);
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<'\n';
		// cerr<<Check(3)<<endl;
		return 0;
	}

}

int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio (0);
	return akakakak::main();
}


