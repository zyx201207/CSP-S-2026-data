#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
const int N = 5e2 + 5; // lines
const int M = 1e3 + 5; // nodes
const int MAX = (M << 2);
using namespace std;

int c,n,m,d,q;
int w[M];
int k[N]; int a[N][M],t[N][M];
int x,y;

int tot,cnt,sum;
ll f[MAX][MAX];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// 对于第 i 个站台，有站厅为 i+2sum，地铁口为 i+3sum 
	memset(f,0x3f,sizeof f);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		sum += k[i];
		for(int j = 1;j <= k[i];j++) scanf("%d%d",&a[i][j],&t[i][j]);
	}
	tot = (sum << 2);
	for(int i = 1;i <= m;i++) f[i + (sum << 1)][i + (sum << 1) + sum] = f[i + (sum << 1) + sum][i + (sum << 1)] = w[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[i];j++){
			if(j - 1) f[j - 1 + cnt][j + cnt] = f[j + cnt][j - 1 + cnt] = 0;
			f[a[i][j] + (sum << 1)][j + cnt] = f[j + cnt][a[i][j] + (sum << 1)] = t[i][j];
		}
		cnt += k[i];
	}
	for(int k = 1;k <= tot;k++){
		for(int i = 1;i <= tot;i++){
			for(int j = 1;j <= tot;j++) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%lld\n",f[x + (sum << 1) + sum][y + (sum << 1) + sum]);
	}
	return 0;
}

