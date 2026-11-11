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

signed main () {
	
	//freopen ("subway.in","r",stdin);
	//freopen ("subway.out","w",stdout);
	
	
	
	return 0;
} 
