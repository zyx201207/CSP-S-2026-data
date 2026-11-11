#include<bits/stdc++.h>

using namespace std;
int n;
long long b, q;
string g;
struct a{
	int l;
	char j;
};
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a u[n];
	for(int i = 0; i < n; ++i) {
		cin >> u[i].l >> u[i].j; 
		b += u[i].l;
	}
	int i = 0, k = n - 1;
	while(b > 0) {
		if(u[i].j != u[k].j) {
			if(u[i].l == u[k].l) {
				q += u[i].l;
				b -= 2*(u[i].l);
				i ++; k --;
			}else if(u[i].l > u[k].l) {
				q += u[k].l;
				b -= 2*(u[k].l);
				u[i].l -= u[k].l;
				k --;
			}else{
				q += u[i].l;
				b -= 2*(u[i].l);
				u[k].l -= u[i].l;
				i ++;
			}
		}else{
			if(u[i].l == u[k].l) {
				b -= 2*(u[i].l);
				i ++; k --;
			}else if(u[i].l > u[k].l) {
				b -= 2*(u[k].l);
				u[i].l -= u[k].l;
				k --;
			}else{
				b -= 2*(u[i].l);
				u[k].l -= u[i].l;
				i ++;
			}
		}
		if (i == k) {
			break;
		}
	}
	cout << q;
	return 0;
} 
