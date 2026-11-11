#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define intl long long
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
	intl x=0,k=1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return x*k;
}
intl n, k, dis[N], id[N];
vector<intl> g[N];

void solve() {
	n = read();
	For(i,2,n) {
		intl u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
	}
	intl ans = 0;
	For(i,1,n) dis[i] = 0;
}
bool check(intl x) {
	intl l1 = x+1, r2 = n-x;
	return r2-l1-k<= x;
}
void solveA() {
	n = read(), k = read();
	For(i,2,n) {
		intl u = read(), v = read();
		g[u].push_back(v), g[v].push_back(u);
	}
	intl m = n/2;
	intl l = 0, r = m, ans = 0;
	while(l <= r) {
		intl mid = (l+r)>>1;
		if(check(mid)) r = mid-1, ans = mid;
		else l = mid+1;
	}  
	printf("%lld\n", ans);
}
void clearA() {
	For(i,1,n) g[i].clear();
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	intl c =read(),T = read();
	if(c) while(T --) solveA(), clearA();
	else while(T --) solve(); 
	return 0;
}


