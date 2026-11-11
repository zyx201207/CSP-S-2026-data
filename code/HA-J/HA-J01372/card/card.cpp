#include<bits/stdc++.h>
using namespace std;

int ind[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ind[i + 1] += n;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if(a[i] == a[j]) {
				for (int l = i + 1; l < j; l++)
					ind[a[l]] -= 2;
				ind[a[i]] ++;
			}
		}
		for (int k = i - 1; k >= 0; k--) ind[a[k]] --;
	}
	
	for (int i = 1; i <= m; i++) {
		cout << ind[i] << " ";
	}
	return 0;
}
