#include<bits/stdc++.h>
#define il inline
#define gtc() getchar()
#define ptc(a) putchar(a)
using namespace std;
namespace IO {
	il void read(int &N) {
		int n=0,f=1;
		char c=gtc();
		while(c<'0' || c>'9') {
			if(c=='-') f=(~f+1);
			c=gtc();
		}
		while(c>='0' && c<='9') {
			n=(n<<3)+(n<<1)+(c^48);
			c=gtc();
		}
		N=n*f;
	}
	il void write(int n) {
		if(n<0) ptc('-'),n=(~n+1);
		if(n>9) write(n/10);
		ptc((n%10)|48);
	}
}
using namespace IO;
const int N=500005,M=300005;
int n,m,a[N],ans[M],cnt[M],tot,h[N],nxt[M],sz,v[N];
int mn[N];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) {
		read(a[i]);
		if(!nxt[a[i]]) nxt[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		if(nxt[a[i]]) {
			for(int j=nxt[a[i]];j<=i;j++) v[a[j]]=1;
			
		}else {
			v[a[i]]=0;
		}
		for(int j=1;j<=nxt[a[i]];j++) if(!v[a[j]]) cnt[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

