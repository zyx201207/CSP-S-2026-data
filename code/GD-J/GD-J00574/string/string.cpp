#include <bits/stdc++.h>
#define int unsigned long long
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
		x=x*10+(ch-'0');
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
	
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	
	int n=read ();
	vector <int> a (n);
	vector <char> c (n);
	for (int i=0;i<n;i++) {
		a[i]=read ();
		c[i]=getchar ();
	}
	
	int ans=0;
	int l=0,r=n-1;
	int lai=a[l],rai=a[r];
	
	while (l<=r) {
		if (c[l]!=c[r]) {
			if (lai>0 && rai>0) {
				if (lai>=rai) {
					ans+=rai;
					lai-=rai;
					rai=0;
				} else {
					ans+=lai;
					rai-=lai;
					lai=0;
				}
			}
		} else {
			if (lai>=rai) {
				lai-=rai;
				rai=0;
			} else {
				rai-=lai;
				lai=0;
			}
		}
		if (lai==0) {
			l++;
			lai=a[l];
		}
		if (rai==0) {
			r--;
			rai=a[r];
		}
	}
	
	write (ans); putchar ('\n');
	
	return 0;
}
