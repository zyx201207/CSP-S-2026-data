#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
struct node{int id, cnt, nxt, lst;}a[N];
bool cmp(node a, node b){return a.lst < b.lst;}
int s[N], in[N], n, m;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> in[i];
	for(int i = 1; i <= n; i++){
		a[in[i]].cnt++;
		a[in[i]].lst = i;
		a[in[i]].nxt = in[i + 1];
		a[in[i]].id = in[i];
	}
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		s[a[i].id] += a[i].cnt;
		if(a[i].nxt != 0) s[a[i].nxt] += s[a[i].id];
	}
	for(int i = 1; i <= m; i++) cout << s[i] << " ";
	return 0;
}
