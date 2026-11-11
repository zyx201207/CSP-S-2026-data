#include<bits/stdc++.h>
using namespace std;
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
int n, m;
int a[N];
int main() {
//	freopen("and5.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	int ans = 0;
	per(j, 29, 0) {
		int nw = ans | (1 << j);
		int cnt = 0;
		rep(i, 1, n) {
			if ((a[i]&nw) == nw) cnt++;
		}
		if (cnt >= m) ans = nw;
	}
	printf("%d", ans);
	return 0;
}
