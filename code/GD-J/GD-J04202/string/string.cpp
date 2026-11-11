#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return (x<y?x=y,1:0);}
template<class T>bool ckmin(T &x,const T y){return (x>y?x=y,1:0);}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
const int N = 2e5 + 10;
int n, a[N];
char s[N];
signed main() {
//	freopen("string6.in","r",stdin);
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
	n = read();
	rep(i, 1, n) a[i] = read(), scanf("%c", s + i);
	int ans = 0;
	int it1 = 1, it2 = n;
	while (it1 != it2) {
		int x = min(a[it1], a[it2]);
		a[it1] -= x, a[it2] -= x;
		if (s[it1] != s[it2]) ans += x;
		if (!a[it1]) it1++;
		else it2--;
	}
	printf("%lld", ans);
	return 0;
}
