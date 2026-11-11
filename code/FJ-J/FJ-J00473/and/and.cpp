#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,a[200005];
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	long long sum = a[n - 1];
	for(int i = n - 2;i >= n - m;i--){
		sum &= a[i];
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12
*/
