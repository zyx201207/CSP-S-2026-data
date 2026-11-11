#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
//ÎÒÒªÄÃ1=£¡qwq 
inline int in(){
	static char ch;
	static int a,f;
	ch=getchar();a=0,f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())a=(a<<1)+(a<<3)+ch-'0';
	return a*f;
}
signed main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	return 0;
}
// >_<
