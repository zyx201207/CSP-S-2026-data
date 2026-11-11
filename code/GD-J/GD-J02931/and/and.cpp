#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
using std :: vector;
using std :: bitset;
#define FileIO(str) freopen(str".in", "r", stdin); freopen(str".out", "w", stdout);
void read(int *x) {
	int f = 1, tmp = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	do {
		tmp = (tmp << 1) + (tmp << 3) + (ch ^ 48);
		ch = getchar();
	} while(isdigit(ch));
	*x = tmp * f;
}
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + 48);
}
int n, m, k, a[200001], cnt, tmp, ans;
bitset<31> bina[200001];
vector<int> sel, wh;
bool skp[200001];
int main(){
	FileIO("and");
	read(&n);
	read(&m);
	for (int i = 1; i <= n; ++i) {
		read(&a[i]);
		bina[i] = a[i];
	}
	for (k = 30; ~k; --k) {
		sel = vector<int>();
		for (int i = 1; i <= n; ++i) {
			if (bina[i][k]) {
				sel.emplace_back(i);
			}
		}
		if (sel.size() >= m) {
			break;
		}
	}
	cnt = sel.size();
	for (; ~k; --k) {
		tmp = 0;
		wh = vector<int>();
		for (int i : sel) {
			if (skp[i]) {
				continue;
			}
			if (!bina[i][k]) {
				wh.emplace_back(i);
			}
			else {
				++tmp;
			}
		}
		if (tmp >= m){
			for (int i : wh) {
				skp[i] = 1;
				--cnt;
				if (cnt == m) {
					break;
				}
			}
		}
		if (cnt == m) {
			break;
		}
	}
	tmp = 0;
	for (int i : sel) {
		if (!skp[i]) {
			++tmp;
			if (ans == 0) {
				ans = a[i];
			}
			else {
				ans &= a[i];
			}
		}
		if (tmp == m) {
			break;
		}
	}
	write(ans);
}
