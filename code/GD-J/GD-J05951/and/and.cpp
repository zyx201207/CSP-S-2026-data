#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n, m, maxx = -1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for (int i = 1; i < n; i ++){
		for (int j = i+1; j <= n; j ++){
			int x = a[i]&a[j];
			maxx = max(x, maxx);
		}
	}
	cout << maxx << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
