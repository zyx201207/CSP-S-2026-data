#include <bits/stdc++.h>
using namespace std;
int a[50005];
double aver[10005][10005];
double n , m;
int main(){
	freopen("crystal1.in" , "r" , stdin);
	freopen("crystal.out" , "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1 , a + (int)n + 1);
	for(int i = 1;i < n;i++){
		a[i] += abs(a[1]);
		aver[i][i] = a[i];
	}
	for(int i = 1;i < n;i++){
		for(int j = i + 1;i <= n;j++){
			aver[i][j] =  (double)(aver[i][j - 1]*(j - i) + a[j]) / (j - i + 1);
		}
	}
	for(int i = n;i >= 1;i--){
		for(int j = 1 ;j <= n - i + 1;j++){
			if((double)m / i >= (a[i + j - 1] - aver[j][j + i - 1])) {cout << i ;break;}
		}
	}
        cout << 3;
	return 0;
}
