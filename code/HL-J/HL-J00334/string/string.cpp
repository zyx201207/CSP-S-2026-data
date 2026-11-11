#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	int n, cnt = 0;
	bool same = true;
	cin >> n;
	int arr[n];
	char str[n];
	for(int i = 0; i < n; i ++) cin >> arr[i] >> str[i];
	for(int i = 1; i < n; i ++) if(str[i] != str[i - 1]) same = false;
	if(n <= 1){
		cout << 0;
		return 0;
	}
	if(same == true){
		cout << "0";
		return 0;
	}
	int x = n / 2;
	for(int i = 0; i < x; i ++){
		if(str[i] != str[n - i - 1]) cnt ++;
	}
	cout << cnt;
	return 0;
} 
