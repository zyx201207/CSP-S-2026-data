#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int a1, b1, a2, b2;
char c1, c2;

inline 
bool f(char a, char b) {
	if (a > b) swap(a, b);
	if (a == 'A' && b == 'B' || a == 'B' && b == 'C' || a == 'D' && b == 'F') return 1;
	return 0;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	cout << (a1 == a2);
	cout << (a1 == a2 && b1 == b2);
	cout << (a1 == a2 && b1 == b2 && ('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C' || 'D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F'));
	cout << (a1 == a2 && ('A' <= c1 && c1 <= 'C' && 'A' <= c2 && c2 <= 'C' || 'D' <= c1 && c1 <= 'F' && 'D' <= c2 && c2 <= 'F') && (b1 == b2 && f(c1, c2) || c1 == c2 && abs(b1 - b2) == 1)) << "\n";
	
	return 0;
}

