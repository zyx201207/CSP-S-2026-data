#include <bits/stdc++.h>
using namespace std;

int arr[30010],cnt[30010],c[30010];
int n, m;

int main() {
	freopen("card.in","r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			c[arr[j]]  = 1;
		}
		for (int j = i; j <= n; j++) {
			cnt[arr[j]] += c[arr[j]];
		
			c[arr[j]] = 0;
		}
	}
	
	cout << cnt[i] << " "; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
