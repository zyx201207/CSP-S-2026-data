#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	int n, m, maxx = -1;
	cin >> n >> m;
	vector<int>a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		for(int j = i+1 ; j <= n; j++)
		maxx = (maxx, (a[i] & a[j]));
	}
	cout << maxx;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
