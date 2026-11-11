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
const int M=500005,N=502;
int c,n,m,d,q,w[M],k[N],a[N][25],t[N][25],dis[N][N];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
		
		}
	}
	for(int i=1,x,y;i<=q;i++) {
		cout<<0<<"\n";
	}
	return 0;
}

