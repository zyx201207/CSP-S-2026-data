#include <cstdio>
#define N 500005

int n, m, a[N], i, j, f, c;
int u[N], w[N], p[N], q[N];
int main(){
	//rp++
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", a+i);
		u[a[i]] = i;
	}
	//u[x]:点数x的最右侧
	//p[i]:i往右跳一次
	//q[x]:目前点数x的最左侧 
	//w[i]:多少个点能保留i 
	for(i=n; i; i--){
		p[i] = q[a[i]];
		q[a[i]] = i;
	}
	for(i=1; i<=n; i++){
		w[i]++;
		if(p[i])	w[p[i]] += w[i];
		else	w[i+1] += w[i];
	}
	for(i=1; i<=m; i++)	printf("%d ", w[u[i]]);
	return 0;
}	//xw
