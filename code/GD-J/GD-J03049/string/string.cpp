#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt, a[2000001];
char c[1000001];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int j = n;
	for (int i = 1;i <= n;i++){
		for (;j >= i;){
			if (c[i] == c[j]){
				if (a[i] > a[j]){
					a[i] -= a[j]; 
					a[j] = 0;
				}else{
					a[j] -= a[i];
					break;
				}
			}else{
				if (a[i] > a[j]){
					cnt += a[j];
					a[i] -= a[j];
					a[j] = 0;
				}else{
					cnt += a[i];
					a[j] -= a[i];
					a[i] = 0;
				}
			}
			if (a[j] == 0){
				j--;
			}
			if (a[i] == 0){
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
