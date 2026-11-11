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
	
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	
	int n=read (),m=read ();
	
	vector <int> card (n+7);
	for (int i=1;i<=n;i++) {
		card[i]=read ();
	}
	
	vector <int> ans (m+7,0);
	for (int i=1;i<=n;i++) {
		stack <int> st;
		vector <bool> lst (m+7,0);
		for (int j=i;j<=n;j++) {
			if (lst[card[j]]) {
				while (!st.empty ()) {
					lst[st.top ()]=0;
					if (st.top ()==card[j]) {
						st.pop ();
						break;
					} else st.pop ();
				}
			} st.push (card[j]);
			lst[card[j]]=1;
		}
		while (!st.empty ()) {
			ans[st.top ()]++;
			st.pop ();
		}
	}
	
	for (int i=1;i<=m;i++) {
		write (ans[i]); putchar (' ');
	} putchar ('\n');
	
	return 0;
}
