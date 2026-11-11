#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
namespace FastIO
{
	const int SIZE=(1<<21)+1;
	char c,ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=obuf+SIZE-1,qu[55];
	int f,qr;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
	template<class I=int>inline I read() {for(f=1,c=gc();c<'0'||c>'9';c=gc()) if(c=='-') f=-1;I x=0;for(;c>='0'&&c<='9';c=gc()) x=(x<<(I)3)+(x<<(I)1)+(c&15);return x*f;}
	inline void putc(char x){if(oS==oT) {fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}*oS++=x;}
	template<class I=int>inline void print(I x){if(!x) putc('0');if(x<0) putc('-'),x=-x;while(x) qu[++qr]=(x%10)+'0',x/=10;while(qr) putc(qu[qr--]);}
	struct Flusher_{~Flusher_(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}}io_flusher_; 
};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}

