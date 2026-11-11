#include<stdio.h>
#include<vector>

int n, m;
std::vector<int> g[35];

inline int sol(int r, int sta){
	int sum;
	for(int i = r; i >= 0; i--){
		if((int)g[i].size() < m) continue;
		sum = 0; for(int k : g[i]) sum += (k & sta) == sta;
		if(sum >= m) return sta | sol(r - 1, sta | (1 << i));
	}
	return sta;
}

int main(){
	freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
	int a, x, cnt;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a); x = a; cnt = -1;
		while(x){
			cnt++;
			if(x & 1) g[cnt].push_back(a);
			x >>= 1;
		}
	}
	printf("%d", sol(29, 0));
}
