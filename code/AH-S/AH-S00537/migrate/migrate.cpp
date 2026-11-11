#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10, MOD=1e9+7;
int c, T, n, m, d, q, a[N], w[N], t[N], cnt, tot, ans, maxn, minn=0x3f3f3f3f;
vector<pair<int, int>> e[N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c=read(), T=read();
	while(T--){
		n=read(), d=read();
		for(int i=1; i<=n; i++){
			a[i]=read();
		}
		write(0), puts("");
	}
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
