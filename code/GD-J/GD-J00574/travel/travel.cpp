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

bool check1 (string s1,string s2) {
	char ch1=s1[0],ch2=s2[0];
	if (ch1<='C' && ch2<='C') return true;
	if (ch1>'C' && ch2>'C') return true;
	return false;
}
bool check2 (string s1,string s2) {
	char ch1=s1[0],ch2=s2[0];
	if (abs (ch1-ch2)==1) return true;
	return false;
}

signed main () {
	
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	string c1,c2,s1,s2; cin>>c1>>s1>>c2>>s2;
	string row1=s1.substr (0,2),row2=s2.substr (0,2);
	string letter1=s1.substr (2,1),letter2=s2.substr (2,1);
	
	string ans="";
	bool flag;
	ans+=(c1==c2 ? '1' : '0');
	flag=(ans[0]=='1');
	ans+=((flag && row1==row2) ? '1' : '0');
	flag=(ans[1]=='1');
	ans+=((flag && check1 (letter1,letter2)) ? '1' : '0');
	flag=(ans[2]=='1');
	ans+=((flag && check2 (letter1,letter2)) ? '1' : '0');
	
	cout<<ans<<'\n';
	
	return 0;
}
