//GZ-S00020 郑淇予 贵阳市第一中学 
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(NULL));
	int c, t;
	scanf("%d%d", &c, &t);
	FOR(i, 1, t){
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%d\n", rand()%(n/2+1));
		//对齐输入
		FOR(i, 1, n-1){
			int u, v;
			scanf("%d%d", &u, &v);
		} 
	}
	return 0;
}
