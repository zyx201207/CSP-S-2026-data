#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[10001000];
int ans, last,cus;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> m >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cus = a[i] & m;

		if (cus <= last){
			ans = last;

		} else {
			ans = a[i];

			last = cus;

		}
	}
	cout << ans;
	return 0;
}
