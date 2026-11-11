#include <bits\stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if(m==1){
		int s=0;
		for(int i = 1; i<=n; i++){
			s = max(s, a[i]);
		}
		cout << s;
		return 0;
	}
	
	int b = a[1], c = a[2];
	for(int i = 2; i<=m; i++){
		b = b&a[i];
	}
	for(int i = 3; i<=m+1; i++){
		c = c&a[i];
	}
	cout << max(b, c);
	return 0;
}
