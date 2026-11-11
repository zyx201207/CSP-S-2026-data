#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, char> a[200010];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int i = 1, sum = 0, j = n;
	for (int k = 1; k <= n; k++){
		int x;
		char y;
		cin >> x >> y;
		a[k] = make_pair(x, y);
	}
	int ret = 0;
	while(i < j){
//		cout << i <<' ' << j << '\n';
		if (a[i].second != a[j].second){
			if (a[i].first < a[j].first){
				sum += a[i].first;
//				cout << 1 << ':' << sum << '\n';
				a[j].first -= a[i].first;
				i++;
			}
			else if (a[i].first > a[j].first){
				sum += a[j].first;
//				cout << a[j].first << '\n';
//				cout << 2 << ':' << sum << '\n';
				a[i].first -= a[j].first;
				j--;
			}
			else{
				sum += a[j].first;
//				cout << 3 << ':' << sum << '\n';
				i++;
				j--;
			}
		}
		else{
			if (a[i].first < a[j].first){
				a[j].first -= a[i].first;
				i++;
			}
			else if (a[i].first > a[j].first){
				a[i].first -= a[j].first;
				j--;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout << sum;
}
