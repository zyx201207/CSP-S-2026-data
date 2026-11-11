# include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, sum;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum = min(sum,a[i]);
	}
	cout << sum;
	return 0;
}
