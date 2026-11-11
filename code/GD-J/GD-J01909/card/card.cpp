#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int step[500005], ans[300005];
bool A = true;
int main(){
//	freopen("card5.in", "r", stdin);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		step[i] = i;
		if(a[i - 1] != a[i] && i != 1){
			A = false;
		}
	}
	if(A && (n > 5000 || m > 3000)){//O(n + m)
		int num = 1, as = a[1];
		for(int i = 2; i <= n; i++){
			if(a[i] != as){
				ans[as] += num;
				num = 1;
				as = a[i];
			}
			else{
				num++;
			}
		}
		ans[as] += num;
		for(int i = 1; i <= m; i++){
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for(int i = n - 1; i >= 1; i--){//step≥ı ºªØ O(nm)
		int j = i + 1;
		while(j <= n){
			if(a[j] == a[i]){
				step[i] = step[j];
				break;
			}
			j++;
		}
	}
//	for(int i = 1; i <= n; i++){
//		cout << step[i] << ' ';
//	}
//	cout << endl;
	for(int i = 1; i <= n; i++){//O(nm)
		int j = i;
		while(j <= n){
			if(step[j] != j){
				j = step[j];
			}
			else{
				ans[a[j]]++;
				j++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
