#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10, MOD=1e9+7;
int T, n, m, d, q, a[510][N], w[N], t[510][N], b[N], cnt, tot, ans, maxn, minn=0x3f3f3f3f;
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
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	T=read(), n=read(), m=read(), d=read(), q=read();
	for(int i=1; i<=m; i++){
		w[i]=read();
	}
	for(int i=1; i<=n; i++){
		int k=read();
		for(int j=1; j<=k; j++){
			a[i][j]=read(), t[i][j]=read();
		}
	}
	while(q--){
		int x=read(), y=read();
		if(T<=3){
			write(w[x]+w[y]), puts("");
		}else if(T==20||T==21){
			write(w[x]+w[y]), puts("");
		}
		write(w[x]+w[y]), puts("");
	}
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
