#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m,k = 0,a[999999],c[999999] = {0};
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int i = 0;i < n;i++){
		int x = 0,b[999999] = {0};
		
		for (int j = i;j < n;j++){
			for (int q = 0;q < x;q++){
				if (b[q] == a[j]){
					x = q;
					break;
				}
				else {
					b[x] = a[j];
				}
				x++;
			}
		}
		for (int j = 0;j < x;j++){
			c[b[j]]++;
		}
	}
	for (int i = 1;i <= m;i++){
		cout << c[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
