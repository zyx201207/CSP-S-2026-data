#include <bits/stdc++.h>
using namespace std;
#define N 200050
int i, j, k, n, m, a[N], f[N], p, l, o;
void dfs(int k, int u){
	if(u<p) return;
	if(k>m){
		if(u>p) p=u;
		return;
	}
	else {
		for(int i=1; i<=n; i++){
			if(f[i]) continue;
			f[i]=1;
			dfs(k+1, u&a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(i==1) o=a[i];
		o=o&a[i];
		l=max(a[i], l);
	}
	if(m==1) printf("%d\n", l);
	else if(m==n) printf("%d\n", o);
	else {
		for(i=1; i<=n; i++){
			f[i]=1;
			dfs(2, a[i]);
			f[i]=0;
		}
		printf("%d\n", p);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
