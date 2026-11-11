#include<bits/stdc++.h>
using namespace std;
int n,m,k[509],d,q,z[500009][23],t[500009][23],fcnt[500009],w[500009];
long long e[509][509];//e[i][j]是从地铁线i换乘地铁线j的最小用时 
void rd(int &x){
	char c = getchar();
	x = 0;
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
		x = x * 10 + c - '0',c = getchar();
}
void wt(long long x){
	if(x > 9)
		wt(x / 10);
	putchar(x % 10 + '0');
}
int main(){
//	cerr << 8. * 500009 * 23 / 1024 / 1024 << endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rd(n),rd(n),rd(m),rd(d),rd(q);
	memset(e,0x3f,sizeof(e));
	for(int i = 1; i <= m; i ++)
		rd(w[i]);
	for(int i = 1; i <= n; i ++){
		rd(k[i]);
		e[i][i] = 0;
		for(int j = 1; j <= k[i]; j ++){
			int a,xw;
			rd(a),rd(xw);
			fcnt[a] ++;
			z[a][fcnt[a]] = i;
			t[a][fcnt[a]] = xw;
			for(int l = 1; l < fcnt[a]; l ++){
				e[i][z[a][l]] = e[z[a][l]][i] = min(e[i][z[a][l]],1ll * xw + t[a][l]);
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			long long o = e[j][i];
			for(int k = 1; k <= n; k ++){
				e[j][k] = min(e[j][k],o + e[i][k]);
			}
		}
	}
	for(int i = 1; i <= q; i ++){
		int x,y;
		rd(x),rd(y);
		long long ans = 99824435399911659ll;
		for(int j = 1; j <= fcnt[x]; j ++){
			for(int k = 1; k <= fcnt[y]; k ++){
				ans = min(ans,e[z[x][j]][z[y][k]] + t[x][j] + t[y][k]);
			}
		}
		wt(ans + w[x] + w[y]);
		puts("");
	}
}
