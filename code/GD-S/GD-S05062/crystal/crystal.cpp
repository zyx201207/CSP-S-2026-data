#include<iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long arr[500005];
long long b[500005];
long long c[500005];
long long ans;

int main (){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)    cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1;i <= n;i++)    b[i] = b[i - 1] + arr[i];
	for (int i = 1;i <= n;i++)    c[i] = c[i - 1] + b[i];
	long long t = 0;
	long long l = 1;
	for (int i = 1;i <= n;i++){
		t += (i - l) * (arr[i] - arr[i - 1]);
		while (t > m){
			t -= arr[i] - arr[l];
//			t -= (b[i] - b[l]);
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
//	long long t = 0;
//	for (int i = 1;i <= n;i++){
//		t += (i - 1) * (arr[i] - arr[i - 1]);
//		if (t > m){
//			
//		}
//	}
//	if (t <= m)    cout << n;
	return 0;
} 
