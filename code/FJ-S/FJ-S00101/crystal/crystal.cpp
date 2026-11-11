#include<bits/stdc++.h>
using namespace std;

long long a[100000005];
int x = 0;
int js = 0;
long long shu = -10000000;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < m;i++) {
		if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
			a[x]++;
			x = 0;
		} else {
			x++;
			if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
				a[x]++;
				x = 0;
			} else {
				x++;
				if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
					a[x]++;
					x = 0;
				} else {
					x++;
					if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
						a[x]++;
						x = 0;
					} else {
						x++;
						if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
							a[x]++;
							x = 0;
						} else {
							x++;
							if(a[x] != a[x + 1] && a[x] < a[x + 1]) {
								a[x]++;
								x = 0;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0;i < n - 1;i++) {
		shu = a[0];
		if (a[i] == shu) {
			js++;
		}
	}
	cout << js;
	return 0;
}
