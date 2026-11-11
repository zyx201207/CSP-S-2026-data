#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 9;
long long n, m, ans = -1000000, a[M], cha[M], sum[M];
bool cmp(long x, long y){
	return x < y;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool A = true, B = true;
	int tj = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i != 1){
			if(a[i] != i){
				A = false;
			}
		} 
		if(i == 2){
			tj = a[2] - a[1];
		}
		if(i >= 3){
			if(a[i] - a[i - 1] != tj){
				B = false;
			}
		}
	}
	if(A || B){
		ans = 1;
		for(int i = n - 1; i >= 1 ; i--){
			if(m > abs(a[i + 1] - a[i])){
			
				m -= abs(a[i + 1] - a[i]);
				ans++;
				a[i] = a[i + 1];
			}
			else{
				break;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
//	for(int i = 1;  i <= n; i++){
//		cout << a[i] << endl;
//	}
//	cout << a[1] << ' ';
//	for(int i = 2; i <= n; i++){
//		cha[i] = a[i] - a[i - 1];
//		sum[i] = sum[i - 1] + cha[i];
//		cout << a[i] << ' ';
//	}
	for(int i = 1; i <= n; i++){
		long long s = m, x = 1;//now = a[i - 1], shang = a[i];
		for(int j = i - 1; j >= 1; j--){
			if(s > a[i] - a[j]){
				s -= a[i] - a[j];
				x++;
			}
			else{
				break;
			}
		}
		for(int j = i + 1; j <= n; j++){
			if(a[j] == a[i]){
				x++;
			}
			else{
				break;
			}
		}
		if(x > ans){
//			cout << x << '\n';
			ans = x;
		}
	}
	cout << ans <<  '\n';
	fclose(stdin);
	fclose(stdout);
}
