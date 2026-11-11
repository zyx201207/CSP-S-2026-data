#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m;
struct node{
	int c, num, idx;
}a[N];
int cnt, p[35];

bool cmp1(node a, node b){return a.num == b.num ? a.c > b.c : a.num > b.num;}
bool cmp2(node a, node b){return a.idx == b.idx ? a.c > b.c : a.idx > b.idx;}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i].c;
		int tmp = a[i].c;
		while(tmp){
			if(tmp & 1) a[i].num ++;
			tmp >>= 1;
		}
	}
	sort(a + 1, a + n + 1, cmp1);
	int now = 0, tmp = a[1].c;
	while(tmp){
		if(tmp & 1) p[++cnt] = now;
		now ++; tmp >>= 1;
	}
	for(int i = 1; i <= n; i ++){
		for(int j = cnt; j >= 1; j --)
			if((a[i].c >> p[j]) & 1){
				a[i].idx = p[j];
				break;
			}
	}
	sort(a + 1, a + n + 1, cmp2);
	int ans = INT_MAX;
	for(int i = 1; i <= m; i ++)
		ans &= a[i].c;
	cout << ans;
	return 0;
}

