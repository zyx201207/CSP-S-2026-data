#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char a_c[200005];
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> a_c[i]; 
	}
	long long num = 0;
	int l = 1,r = n;
	int xj = 0;
	while(l <= r){
		if (a_c[l] != a_c[r]){
			if (a[l] > a[r]){
				num += a[r];
				a[l] -= a[r];
				r --;
			}
			else if (a[l] < a[r]){
				num += a[l];
				a[r] -= a[l];
				l ++;
			}
			else{
				num += a[l];
				l ++;
				r --;
			}
		}
		else{
			if (a[l] > a[r]){
				a[l] -= a[r];
				r--;
				continue;
			}
			else if(a[l] > a[r]){
				a[r] -= a[l];
				l ++;
				continue;
			}
			else{
				l ++;
				r --;
			}
		}
	} 
	cout << num;
}
