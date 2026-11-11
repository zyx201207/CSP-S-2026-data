#include<bits/stdc++.h>
using namespace std;
#define fo(i, a, b) for(int i = (a); i <= (b); i++)
#define ro(i, a, b) for(int i = (a); i >= (b); i--)
#define int long long 

const int N = 2e5 + 5;
int n, m;
int a[N];


void spe() {
	sort(a + 1, a + 1 + n, greater<int>());
	int anss = a[1];
	fo(i, 2, m) {
		anss &= a[i];
	}
	cout << anss;
}


signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	fo(i, 1, n) {
		cin >> a[i];
	}
	
	//if(n > 20) {
		spe();
		return 0;
	//}
	
	return 0;
}
/*
4 2
3 15 12 12


5 3
31 3 1 15 7
*/
