#include<bits/stdc++.h>
using namespace std;
int N = 1e5+5;
int main() {
	int arr[N], n, m;
	int number = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n - i - 1; j++){
			if(arr[j+1] < arr[j]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = arr[j];
			}
		}
	}
	int min[N];
	for(int i = 1; i <= n; i++){
		min[i-1] = arr[i] - arr[i-1];
	}
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1; i++){
			if(min[j] > min[j+1]){
				int k = min[j];
				min[j] = min[j+1];
				min[j+1] = k;
			}
			
		}
	}
	for(int i = 0; i < n-1; i++){
		int a = min[i];
		if(a <= m){
			m -= a;
			number+=1;
		}
	}
	cout << number << '\n';
	return 0;
}
