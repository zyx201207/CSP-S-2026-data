#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
/*bool cmp(long long x, long long y){
	if(x<y)return 1;
}*/
int main () {
	freopen("and.in","r",stdin);  
	freopen("and.out","w",stdout);cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	/*for (int i = 1; i <= n; i++){
		cout << a[i] << endl;
	}*/
	sort(a+1,a+n+1);
	/*for (int i = 1; i <= n; i++){
		cout << a[i] << endl;
	}*/
	int ans = a[n];
	for (int i = n-1; i >= m; i--){
		cout << a[i] << " " << ans << endl;
		ans&=a[i];
	}
	cout << ans;
}
