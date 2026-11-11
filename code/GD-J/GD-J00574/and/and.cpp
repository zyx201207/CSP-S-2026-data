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

vector <vector <int> > into2 (37);
void change (int x,int i) {
	int pos=0;
	while (x) {
		if (x%2==1) into2[pos].push_back (i);
		x/=2; pos++;
	}
}

signed main () {
	
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	
	int n=read (),m=read ();
	
	for (int i=0;i<n;i++) {
		int ai=read ();
		change (ai,i);
	}
	
	int st=-1;
	vector <int> ans;
	
	vector <bool> cntlst (n+7,false);
	
	for (int i=31;i>=0;i--) {
		if (into2[i].size ()<m) continue;
		else {
			st=i;
			ans.push_back (i);
			for (auto j : into2[i]) {
				cntlst[j]=1;
			}
			break;
		}
	}
	
	if (st==-1) {
		write (0); putchar ('\n');
		return 0;
	}
	
	for (int i=st-1;i>=0;i--) {
		if (into2[i].size ()<m) continue;
		int cnt=0;
		vector <bool> newlst (n+7,false);
		for (auto j : into2[i])
			if (cntlst[j]) {
				newlst[j]=1;
				cnt++;
			}
		if (cnt>=m) ans.push_back (i);
		cntlst=newlst;
	}
	
	int result=0;
	for (auto i : ans) {
		result+=(1<<i);
	}
	write (result); putchar ('\n');
	
	return 0;
}
