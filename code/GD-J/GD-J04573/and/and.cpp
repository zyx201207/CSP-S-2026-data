#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], maxx[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, ml = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans = a[n];
	cout << ans << endl;
	for(int i = n - 1; i >= (n-m+1); i--){
		ans = (ans & a[i]);
	}
	cout << ans <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
