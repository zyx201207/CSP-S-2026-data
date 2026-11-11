#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, m;
int a[N], f[N];
int lst[N];
int s[N];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int t = 0;
	for(int i = 1; i <= n; i ++){
		fill(lst + 1, lst + m + 1, 0);
		t = 0;
		for(int j = i; j <= n; j ++){
			if(lst[a[j]]){
				while(t > 0 && s[t] != lst[a[j]]){
					lst[a[s[t]]] = 0;
					t --;
				}
				if(t > 0 && s[t] == lst[a[j]]){
					t --;
				}
			}
			lst[a[j]] = j;
			s[++ t] = j;
		}
		for(int i = 1; i <= t; i ++){
			f[a[s[i]]] ++;
		} 
	}
	for(int i = 1; i <= m; i ++){
		cout << f[i];
		if(i < m) cout << ' ';
	}
	return 0;
}
