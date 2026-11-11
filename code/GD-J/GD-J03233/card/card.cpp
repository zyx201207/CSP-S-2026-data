#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e5+10, M = 3e5+10;
int n, m, a[N], last[N], tail, head, l[N], r[N], ans[N];

void link(int x, int y){
	r[x] = y;
	l[y] = x;
}

void init(){
	memset(last, 0, sizeof(last));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	link(head, tail);
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	head = 0;
	tail = n+2;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n <= 500){
		for (int k = 1; k <= n; k++){
			init();
			for (int i = k; i <= n; i++){
				if (last[a[i]] == 0){
					link(l[tail], i);
				}
				else{
					int pzh = last[a[i]];
					for (int j = last[a[i]]; j != tail; j = r[j]){
						last[a[j]] = 0;
					}
					link(l[pzh], i);
				}
				last[a[i]] = i;
				link(i, tail);
			}
			for (int i = r[head]; i != tail; i = r[i]){
				ans[a[i]]++;
			}
		}
		for (int i = 1; i <= m; i++){
			cout << ans[i] << " ";
		}
	}
	else{
		memset(last, 0, sizeof(last));
		for (int i = 1; i <= n; i++){
			last[a[i]] = i;
		}
		for (int i = 1; i <= m; i++){
			cout << last[i] << " ";
		}
	}
	return 0;
}
