#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
int c, t, n, dis[N], cnt[N], sum[N], q[N];
ll d, a[N];
int le[N], re[N];
ll ans;
inline void dp_(int x){//动态规划 
	int hh=1, tt=0;
	q[++tt] = x;
	for(int i=x+1; i<=n; ++i){
		while(hh<=tt && q[hh]<le[i]){//将不在范围内的点出队，去掉贡献
//			printf("出队 %d\n", q[hh]); 
			sum[dis[q[hh]]] -= cnt[q[hh]];
			hh++;
		}
		dis[i] = dis[q[hh]]+1;
		cnt[i] = sum[dis[q[hh]]];
		sum[dis[i]] += cnt[i]; 
		while(hh<=tt && dis[q[tt]]>dis[i]) --tt;//维护单调性 
		q[++tt] = i;
//		printf("入队 %d\n", i);
	}
}

inline void solve(){
	scanf("%d%lld", &n, &d);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i);
	for(int i=1,l=1,r=1; i<=n; ++i){
		while(l<=i && a[i]-a[l]>d) ++l;
		while(r<n && a[r+1]-a[i]<=d) ++r;
		le[i]=l, re[i]=r;
//		printf("%d%c", le[i], " \n"[i==n]);
	}

	ans = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j) dis[j] = cnt[j] = sum[j] = 0;//初始化
		dis[i] = 0;
		cnt[i] = sum[0] = 1;
		dp_(i);
//		printf("%d\n", i);
		for(int j=i+1; j<=n; ++j){
//			printf("_%d %d %d\n", j, dis[j], cnt[j]);
			if(cnt[j] == 2) ++ans;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) solve();
	return 0;
}
