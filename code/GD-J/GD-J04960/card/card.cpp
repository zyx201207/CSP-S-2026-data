#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1000;
int a[N];
int b[N];
vector <int> ans[N];
int n, m;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		int c[N] = {0};
		c[i] = a[i];
		for(int j = i + 1; j <= n; j++){
			for(int k = 1; k <= j; k++){
				if(ans[a[j]][k] == j && c[ans[a[j]][k - 1]] != 0){
					int h = j;
					while(h >= c[ans[a[j]][k - 1]]){
						c[h] = 0;
						h--;
					}
					break;
				}
			}
			c[j] = a[j];
		}
		int j = n;
		while(c[j] != 0){
			b[c[j]]++;
			j--;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
