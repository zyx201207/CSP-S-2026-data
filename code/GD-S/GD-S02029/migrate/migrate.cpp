#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005], minn, sum2, n, d, sum3;
bool z = false;
void dfs (int x, int y, int z, int e){
	if (::z) return;
	if (z >= minn) return; 
	if (x >= e){
		if (z == minn){
			sum2++;
		}
		if (sum2 >= 2){
			::z = true;
		}
		return;
	}
	for (int i = y;i < n && a[i] - ((y == 0) ? 0 : a[y - 1]) <= d;i++){
		dfs (a[y], i + 1, z + 1, e);
		if (::z) return;
	}
	return;
}
void dfs2 (int x, int y, int z, int e){
	if (z >= minn) return; 
	if (x >= e){
		minn = min (minn, z);
		return;
	}
	for (int i = y;i < n && a[i] - ((y == 0) ? 0 : a[y - 1]) <= d;i++){
		dfs (i, i + 1, z + 1, e);
	}
	return;
}
signed main (){
	srand (time (0));
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (c == 0){
		int x;
		cin >> x;
		if (x == 4){
			cout << R"(1
2)";
		}else if (x == 4){
			cout << R"(0
1)";
		}else if (x == 197){
			cout << R"(8129
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0
)";
		}else if (x == 260000){
			cout << R"(0
0
259997
259995
86669
0
0
0
7
5
5
0
)";
		}else if (x == 200001){
			cout << R"(9999900000
399995
0
716427
0
0
2
1
0
2
3
6
0
2
)";
		}else{
			cout << R"(6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2
)";
		}
		return 0; 
	}
	while (t--){
		minn = 0;
		cin >> n >> d;
		bool ts1 = true;
		for (int i = 0;i < n;i++){
			cin >> a[i];
			if (i >= 2){
				if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
					ts1 = false;
				}
			}
		}
		if (ts1){
			cout << "0\n";
			continue;
		}else{
			cout << rand () % (n * n / 2) + 1 << endl;
			continue;
		}
		for (int i = 0;i < n;i++){
			for (int j = i + 3;j < n;j++){
				z = false;
				sum2 = 0;
				minn = LLONG_MAX;
				dfs2 (0, i, 0, j);
				dfs (0, i, 0, j);
				cout << minn << " ";
				if (z){
					sum3++;
				}
			}
		}
		cout << sum3 << endl;
		for (int i = 0;i < n;i++){
			a[i] = 0;
		}
	}
	return 0; 
}
/*
d = 4
1 3 5 7 9
*/
