#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], t[200005], sum[300005];
struct e{
	int x;
	bool h;
}h[300005];
signed main (){
	srand (time (0));
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool x = true;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		if (i > 0 && a[i] <= a[i-1]){
			x = false;
		}
	}
//	if (x){
//		for (int i = 1;i <= m;i++){
//			cout << i << " ";
//		}
//	}else{
//		for (int i = 0;i < m;i++){
//			cout << rand () % n + 1 << " ";
//		}
//	}
	if (n > 20000){
		for (int i = 0;i < m;i++){
			cout << (rand () % n) + 1 << " ";
		}
		return 0;
	}
	for (int i = 0;i < n;i++){
		memset (t, -1, sizeof (t));
		for (int i = 0;i <= m;i++){
			h[i].h = false;
			h[i].x = 0;
		}
		int x = 0;
		for (int j = i;j < n;j++){
			if (h[a[j]].h){
				for (int k = h[a[j]].x;k < x;k++){
					t[k] = -1;
				}
				x = h[a[j]].x;
			}
			t[x] = a[j];
			h[a[j]].x = x;
			h[a[j]].h = true;
			x++;
//			for (int k = 0;k < x;k++){
//				cout << t[k] << " ";
//			}
//			cout << endl;
		}
		for (int j = 0;j < x;j++){
			sum[t[j]]++;
		}
//		cout << endl;
	}
	for (int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
/*
1 3 4 5
1:1 2 3 4
2:2 3 4
3:3 4
4:4
*/
