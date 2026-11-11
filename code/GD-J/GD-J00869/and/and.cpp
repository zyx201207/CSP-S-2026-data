#include <bits/stdc++.h>
using namespace std;

long long temp, n, m, a[400005];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n>> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (m == 2){
		for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				temp = max(temp, a[i] & a[j]);
			}
		}
	}else if(m == 1){
		for (int i = 1;i <= n;i++){
			temp = max(a[i], temp);
		}
	}
	cout << temp;
}
