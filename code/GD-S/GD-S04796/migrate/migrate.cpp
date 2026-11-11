#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in", "in", stdin);
	freopen("migrate.out", "out", stdout);

	int n = 0, d = 0;
	cin >> n >> d;
	vector<int> arr(n, 0);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	if(arr[0] < 0){
		for(int i = 0;i < n;i++){
			arr[i] += (-arr[0]);
		}
	}
	vector<int> reach(n, 0);
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[j] - arr[i] <= d)
				reach[i] = j;
		}
	}
	int cnt = 0;
	for(int l = 0;l < n;l++){
		int r = reach[l] + 1;
		if(r >= n) continue;
		bool check = true;
		for(int i = l + 1;i < r;i++){
			if(reach[i] < r){
				check = false;
				break;
			}
		}
		if(check) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
