#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

inline int read () {
	int x=0,f=1;
	char ch=getchar ();
	while (!isdigit (ch)) {
		if (ch=='-') f=-1;
		ch=getchar ();
	}
	while (isdigit (ch)) {
		x=x*10+ch-'0';
		ch=getchar ();
	}
	return x*f;
}
inline void write (int x) {	
	if (x<0) {
		putchar ('-');
		x=-x;
	}
	if (x>=10) write (x/10);
	putchar (x%10+'0');
}

int n,m;
const int N=5e5+7;
int a[N];

signed main () {
	
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	
	n=read (),m=read ();
	
	for (int i=1;i<=n;i++) {
		a[i]=read ();
	}
	
	sort (a+1,a+1+n);
	
	bool flagA=true,flagB=true;
	for (int i=0;i<n;i++) {
		if (a[i]!=i) flagA=false;
		if (i>0 && a[i]-a[i-1]!=a[i+1]-a[i]) flagB=false;
	}
	
	if (flagA) {
		for (int i=n;i>0;i--) {
			if (i*(i-1)/2<=m) {
				write (i); putchar ('\n');
				return 0;
			}
		}
	}
	if (flagB) {
		int df=a[2]-a[1];
		for (int i=n;i>0;i--) {
			if (i*(i-1)/2*df<=m) {
				write (i); putchar ('\n');
				return 0;
			}
		}
	}
	
	int ans=-inf;
	for (int i=0;i<n;i++) {
		int aim=a[i];
		
		int cnt=1;
		int tm=m;
		
		for (int j=i-1;j>=0;j--) {
			int diff=aim-a[j];
			if (m-diff>=0) {
				m-=diff;
				cnt++;
			} else break;
		}
		ans=max (ans,cnt);
		
		m=tm;
	}
	
	write (ans); putchar ('\n');
	
	return 0;
}
