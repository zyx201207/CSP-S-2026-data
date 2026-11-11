#include <bits/stdc++.h>
using namespace std;
#define int long long
struct e{
	int a;
	char c;
}a[200005];
int sum, n, sum2, sum3, pos, sum4;
signed main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a[i].a >> a[i].c;
	}
	pos = n - 1;
	sum4 = a[pos].a;
	for (int i = 0;i < n;i++){
		sum3 += a[i].a;
		while (sum2 < sum3){
			if (sum4 <= sum3){
				if (a[pos].c != a[i].c){
					sum += abs (sum4 - sum2);
				}
				sum2 = sum4;
				pos--;
				sum4 += a[pos].a;
			}else{
				if (a[pos].c != a[i].c){
					sum += (sum3 - sum2);
				}
				sum2 = sum3;
			}
		}
	}
	cout << sum / 2;
	return 0;
}
/*
abcccccbbaa
abcccccccba
*/
