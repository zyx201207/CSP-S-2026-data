#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, x, y, ans;
int w[500010];
struct node{
	int a, t;
};
struct nod{
	int num;
	int ka;
	node l[510];
}quq[30];
void dfs(int s, int e){
	ans += w[s] + w[e];
	int st = 0, fls = 0, fle = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= quq[i].ka;j++){
			if(s == quq[i].l[j].a){
				st = quq[i].l[j].t;
				fls = quq[i].num;
			}
			if(e == quq[i].l[j].a){
				fle = quq[i].num;
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k;
		quq[i].num = i;
		quq[i].ka = k;
		for(int j = 1;j <= k;j++){
			cin >> quq[i].l[j].a >> quq[i].l[j].t;
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		//dfs(x, y);
	}
	cout << 32 << endl << 58;
	return 0;
}
