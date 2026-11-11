# include <bits/stdc++.h>
using namespace std;

const int N = 52111314; // To yi 
int a[N];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout); 
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= m; i++) {
		cout << n << " ";
	} 
	
	cout << endl;
	return 0;
}

// 52春意 感谢陪伴我度过备赛的女朋友 会赢吗？ 会赢的！ 明年再战，愿你仍在我左右 
