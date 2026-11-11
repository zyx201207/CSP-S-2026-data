#include <iostream>
using namespace std;
int n, m;
int a[200005];
int f;
int ans[200005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < a[i - 1]) f = 1;
	}
	if(!f){
		int pos = 1;
		int t = 0;
		for(int i = 1; i <= m; i++){
			for(int j = pos; a[j] == i; j++){
				ans[i]++;
				pos++;
			}
		}
		cout << ans[1] << " ";
		for(int i = 2; i < m; i++){
			ans[i] += ans[i - 1];
		}
		for(int i = 2; i < m; i++) cout << n - ans[i] + 1 << " ";
		cout << n; 
	}
	return 0;
}
