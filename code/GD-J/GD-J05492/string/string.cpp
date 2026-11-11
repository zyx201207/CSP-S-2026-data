#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ull unsigned long long

using namespace std;

const int MAXN=2e5+5;
int n,pos,p,len[MAXN];
char a[MAXN];
ull ll;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int l;char c;
		scanf("%d%c%c",&l,&c,&c);
		len[i]=l;
		a[i]=c;
		ll+=l;
	}
	ull _ll=0;
	for(int i=1;i<=n;i++) {
		if(_ll+len[i]>(ll>>1)) {
			pos=i;
			p=(ll>>1)-_ll;
			break;
		}
		_ll+=len[i];
	}
	//printf("%lld %d %d\n",ll,pos,p);
	ull cnt=0;
	int l=p-1,r=p+1,pl=pos,pr=pos;
	if(!(ll&1)) r=p;
	if(l<0) {
		pl--;
		l=len[pl]-1;
	}
	if(r>=len[pr]) {
		pr++;
		r=0;
	}
	
	while(pl&&pr<=n) {
		//printf("%d %d %d %d\n",l,pl,r,pr);
		if(l+1>len[pr]-r) {
			// 查右边 
			if(a[pl]!=a[pr]) {
				cnt+=len[pr]-r;
			}
			l-=(len[pr]-r);
			r=0;
			pr++;
		} else if(l+1<len[pr]-r) {
			// 查左边 
			if(a[pl]!=a[pr]) {
				cnt+=l+1;
			}
			r+=(l+1);
			pl--;
			l=len[pl]-1;
		} else {
			// 一起查 
			if(a[pl]!=a[pr]) {
				cnt+=len[pr]-r;
			}
			pl--;
			l=len[pl]-1;
			r=0;
			pr++;
		}
	}
	
	// 朴素法，仅供参考 
//	while(pl&&pr<=n) {
//		if(l<0) {
//			pl--;
//			if(!pl) break;
//			l=len[pl]-1;
//		}
//		if(r>=len[pr]) {
//			pr++;
//			if(pr>n) break;
//			r=0;
//		}
//		if(a[pl]!=a[pr]) cnt++;
//		//printf("%d %d %d %d\n",pl,pr,l,r);
//		l--;
//		r++;
//	}
	printf("%lld",cnt);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
 
