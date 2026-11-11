#include <bits/stdc++.h>
using namespace std;

int n, m, l[200005], ans;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	int n, m, l[200005], ans;
	cin  >> n >> m;
	for(int i=0; i<n; i++){
		cin >> l[i];
	}
	sort(l, l+n);
	ans = l[n-1];
	for(int i=n-1; i>=n-m; i--){
		//cout << l[i] << "&";
		ans = ans & l[i];
	}
	cout << ans;
}
