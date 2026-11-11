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
const int M=2003,N=2003;      /////////////////////////////////////////////////////////////////////
int n,m,a[N],f[N][M];
bool pd(int n) {
	n++;
	while(n) {
		if(n&1) return false;
		n>>=1;
	}
	return true;
}
bool ok() {
	for(int i=1;i<=n;i++)
		if(!pd(a[i])) return false;
	return true;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	if(n<=2000 && m<=2000) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				f[i][j]=2147483647;
		for(int i=1;i<=n;i++) f[i][1]=a[i];
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--) {
				if(f[i][j]==2147483647 && f[i-1][j-1]!=2147483647) {
					f[i][j]=(f[i-1][j-1]&a[i]);
				}else {
					f[i][j]=max(f[i][j],(f[i-1][j-1]&a[i]));
				}
			}
		write(f[n][m]);
	}else if(m==n) {
		int ans=2147483647; 
		for(int i=1;i<=n;i++) ans&=a[i];
		write(ans);
	}else if(ok()) {
		int ans=2147483647;
		sort(a+1,a+1+n);
		for(int i=n;i>=n-m+1;i--) ans&=a[i];
		write(ans);
	}else if(m==n-1) {
		int cnt=2147483647,ans=0;
		for(int i=1;i<=n;i++) cnt&=a[i];
		for(int i=1;i<=n;i++) ans=max(ans,(cnt|(a[i])));
		write(ans);
	}
	return 0;
}
