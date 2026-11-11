#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	bool A = (a == c);
	cout << A;
	bool B = (b.substr(0, 2) == d.substr(0, 2));
	cout << (A && B);
	int C = (b[2] <= 'C' && d[2] <= 'C') || ('D' <= b[2] && b[2] <= 'F' && 'D' <= d[2] && d[2] <= 'F');
	cout << ((A && B) && C);
	bool D = (abs(b[2]-d[2]) == 1);
	cout << (A && B && C && D);
	
	
	
	return 0;
}
