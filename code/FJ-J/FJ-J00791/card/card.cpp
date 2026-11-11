#include<bits/stdc++.h>
using namespace std;
int a[500009], b[300009], c[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = n;i >= 1;i--){
		if (b[a[i]] != 0){
			continue;
		}
		for (int j = 1;j <= m;j++){
			c[j] = 0;
		}
		b[a[i]] = 1;
		int f = 1;
		int d[n + 1];
		for (int j = i - 1;j >= 1;j--){
			d[j] = 0;
			if (c[a[j]] != 0){
				b[a[i]] += d[c[a[j]]];
				d[j] = d[c[a[j]]];
				c[a[j]] = j;
			}
			if (f == 1 && b[a[j]] == 0 && c[a[j]] == 0){
				b[a[i]]++;
				d[j] = 1;
				c[a[j]] = j;
			}
			else if (a[j] == a[i]){
				b[a[i]]++;
				d[j] = 1;
				f = 1;
			}
			else if (b[a[j]] != 0){
				f = 0;
			}
			if (b[a[j]] == 0){
				c[a[j]] = j;
			}
		}
	}
	for (int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
