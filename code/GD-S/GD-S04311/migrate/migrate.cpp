#include <bits/stdc++.h>
#define N 1000060
#define ll long long
using namespace std;
ll m, n, i, j, k, a[N], d, T, f[N], c;
void dfs(int a, int b){
	m += f[a] - b;
	if((f[a] == b+1||f[a]==b)&&(f[b] == f[a]+1||f[b] == f[a])&&f[a] != a&&f[b] != b) dfs(f[a], f[b]);
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while(T--){
		scanf("%lld%lld", &n, &d);
		for(i=1; i<=n; i++) scanf("%lld", &a[i]);
		m = 0ll, j = 1;
		for(i=1; i<=n; i++){
			if(j < i) j = i;
			while(j<n && a[j+1]-a[i] <= d) j++;
			f[i] = j;//距离小于等于d的最后一个点 
		}
		for(i=1; i<=n; i++){
			if(f[i] - i == 2){
//				printf("%d %d %d %d\n", i, f[i], f[i+1], m);
				dfs(i+1, i+2);// m += f[i+1]-f[i];
//				m += f[i+1] - f[i];
			}
//			else if(f[i]-i > 2) m++;
		}
		printf("%lld\n", m);
	}
	return 0;
}

