#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const long long inf = 1ll << 60;
int n;
long long d,x[N],pre[N],nxt[N],ans,las;
long long dis[N][N],cnt[N][N];
int c,T;
void work(){
	ans = 0;
	scanf("%d%lld",&n,&d);
	for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
	if(c == 11 || c == 12){
		long long ds = x[2] - x[1];
		long long len = d / ds;
		if(len <= 1) ans = 0;
		else{
			ans = n - (len + len) + 1;
			if(ans < 0) ans = 0;
		}
		printf("%lld\n",ans);
		return;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++) dis[i][j] = inf,cnt[i][j] = 0;
	}
	for(int i = 1; i <= n; i++){
		dis[i][i] = 0,las = i,cnt[i][i] = 1;
		for(int j = i; j <= n; j++){
			if(cnt[i][j] == 2) ++ans;
			while(x[las + 1] - x[j] <= d && las < n) ++las;
			for(int k = j + 1; k <= las; k++){
				if(dis[i][k] > dis[i][j] + 1) dis[i][k] = dis[i][j] + 1,cnt[i][k] = cnt[i][j];
				else if(dis[i][k] == dis[i][j] + 1) cnt[i][k] += cnt[i][j];
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
