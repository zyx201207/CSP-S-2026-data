#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5;
ll n, m;
ll a[N + 5];

ll q[102];//每个区间有几个数字 
ll zhishu[32];//2的n次方 
ll ans = 0;
void init(){
	
	for (int i = 0; i <= 31; i++){
		zhishu[i] = 1;
	}
	for (int i = 1; i <= 30; i++){
		for (int j = 1; j <= i; j++){
			zhishu[i] *= 2;
			
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (a[i] == 0){
			q[0]++;
		}
		if (a[i] < zhishu[i]){
			q[i]++;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	init();
	//部分分
	if (m == 1){
		cout << a[n] << endl;
		return 0;
	} 
	if (m == n){
		for (int i = 1; i <= n - 1; i++){
			ans = a[i] & a[i + 1];
		}
		cout << ans << endl;
		return 0;
	} 
	if (m == n - 1){
		for (int i = 2; i <= n - 1; i++){
			ans = a[i] & a[i + 1];
		}
		cout << ans << endl;
		return 0;
	}
	
	//A
	for (int i = 1; i <= n; i++){
		bool flag = false;
		for (int j = 1; j <= 30; j++){
			if (a[i] == zhishu[j] - 1){
				flag = true;
			}
		}
		if (flag == true){
			ans = a[n - m + 1];
		}
		cout << ans << endl;
		return 0;
	}
	//B
	bool flag1 = false;
	for (int j = 1; j <= 30; j++){
		if (n == zhishu[j]){
			flag = true;
			break;
		}
	}
	bool flag2 = true;
	for (int i = 1; i <= n; i++){
		if (a[i] != i - 1){
			flag2 = false;
		}
	}
	if (flag1 == true && flag2 == true){
		for (int i = n; i >= 1; i--){
			
		}
	}
	
	//1-5
	
	for (int i = 20 ;i >= 0; i--){
		for (int j = n; j >= 1; j--){
			if (q[i] >= m){
				for (int z = n; z >= ; z--){
					ans = a[z] & a[z - 1];
				}
			}
		}
	}
	
	
	for (int i = 30 ;i >= 0; i--){
		for (int j = n; j >= 1; j--){
			if (q[i] >= m){
				
			}
		}
	}
	
	
	cout << ans << endl;
	return 0;
}
