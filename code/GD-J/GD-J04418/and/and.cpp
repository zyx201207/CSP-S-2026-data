#include <bits/stdc++.h>
using namespace std;
bool cmp(int l,int r){
	return l > r;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n,m,a[999999],k = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort (a,a + n,cmp);
	for (int i = 0;i < n - m;i++){
		int b = a[i];
		for (int j = i + 1;j < i + m;j++){
			b = b & a[j];
		}
		if (b > k) k = b;
	}
	cout << k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
