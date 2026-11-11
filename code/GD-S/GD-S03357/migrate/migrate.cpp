#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 10;
ll a[maxn];
int f[maxn],g[maxn],sum[maxn];
int n;
ll d;
void sub1_10(){
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		f[i] = 0,g[i] = 1;
		sum[i-1] = 0,sum[i] = 1;
		int lst = i,p = i;
		for(int j = i + 1;j <= n;j++){
			while(lst < j && a[j] - a[lst] > d)++lst;
			if(lst == j)break;
			if(lst > p)p = j - 1;
			f[j] = f[lst] + 1;
			g[j] = min(sum[p] - sum[lst-1],3);
			if(g[j] == 2)++ans;
			sum[j] = sum[j-1] + g[j]; 
		}
	}
	printf("%lld\n",ans);
}
void sub11a12(){
	ll ans = 0;
	f[1] = 0,g[1] = 1;
	sum[1] = 1;
	int lst = 1,p = 1;
	for(int j = 2;j <= n;j++){
		while(lst < j && a[j] - a[lst] > d)++lst;
		if(lst == j)break;
		if(lst > p)p = j - 1;
		f[j] = f[lst] + 1;
		g[j] = min(sum[p] - sum[lst-1],3);
		if(g[j] == 2)ans += n - j + 1;
		sum[j] = sum[j-1] + g[j]; 
	}
	printf("%lld\n",ans);		
}
bool sub13a14(){
	int v = 0;
	for(int i = 1;i <= n;i++)
		if(a[i] - a[1] <= d && a[n] - a[i] <= d){
			v = i;
			break;
		}
	if(!v)return 1;
	ll x1 = 0,x2 = 0,y1 = n + 1,y2 = n + 1;
	if(v < n)while(a[v+1] - a[x1+1] > d)++x1;
	if(v <= n - 2)while(a[v+2] - a[x2+1] > d)++x2;
	if(v)while(a[y1-1] - a[v-1] > d)--y1;
	if(v > 2)while(a[y2-1] - a[v-2] > d)--y2;
	printf("%lld\n",x1 * (y1 - y2) + y1 * (x2 - x1));
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		bool u = 1;
		for(int i = 1;i <= n;i++)
			scanf("%lld",a+i);
		for(int i = 3;i <= n;i++)
			u &= a[i] - a[i-1] == a[i-1] - a[i-2];
		if(u)sub11a12();
		else if(sub13a14())sub1_10();
	}
}

