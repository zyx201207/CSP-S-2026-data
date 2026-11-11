#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int arr[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	if (m == 1){
		int mx = arr[1];
		for (int i = 2; i <= n; i++) mx = max(mx, arr[i]);
		cout << mx;
		return 0;
	}
	if (m == 2){
		int mx = -1;
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				mx = max(mx, (arr[i] & arr[j]));
	cout << mx;
	return 0;
	}
	if (m == n){
		int ans = arr[1];
		for (int i = 2; i <= n; i++) ans = (ans & arr[i]);
		cout << ans;
		return 0;	
	}
	else {
		int minx = arr[1];
		for (int i = 2; i <= n; i++) minx = min(minx, arr[i]);
		cout << minx;	
	}
	return 0;
} 
