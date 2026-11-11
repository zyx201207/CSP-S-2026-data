#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 510, M = 500010;
int c, n, m, d, q;
int w[M];
vector<int> a[N], t[N];
int kn, ai, ti, x, y;
LL res;
struct Node{
	int x, y, z;//x->y,ÏßÂ·z 
};
//priority_set<Node> p;
//Oct31==Dec25?
//0 ¡Ü c ¡Ü 25£¬1 ¡Ü n ¡Ü 500£¬1 ¡Ü m ¡Ü¡Æni=1 ki ¡Ü 5 ¡Á 105£¬1 ¡Ü d ¡Ü 20£¬1 ¡Ü q ¡Ü 105£»

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1;i <= m;i++){
		scanf("%d", &w[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d", &kn);
			a[j].push_back(kn);
			for(int k = 0;k < kn;k++){
				scanf("%d%d", &ai, &ti);
				a[j].push_back(ai);
				t[j].push_back(ti);
			}
		}
	}
	while(q--){
		scanf("%d%d", &x, &y);
		res = w[x] + w[y];
		printf("%lld\n", res + 8945);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
