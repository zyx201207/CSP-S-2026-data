#include <iostream>
#include <cstring>
using namespace std;
int t[300005], n, m, pos;
int jump[500005], a[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		jump[i] = i;
		jump[t[a[i]]] = i;
		t[a[i]] = i;
	}
	for(int i = 0; i <= m; i++) {
		t[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		pos = i;
		while(pos <= n) {
			pos = jump[pos];
			if(pos == jump[pos]) {
				t[a[pos]]++;
				pos++;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << t[i];
		if(i == m) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
