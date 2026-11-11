#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long ans = 0;
struct stu{
	long long num;
	char c;
}arr[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].num >> arr[i].c;
	}
	int l = 1, r = n;
	while(l < r){
		if(arr[l].num > arr[r].num){
			if(arr[l].c == arr[r].c){
				arr[l].num -= arr[r].num;
				r--;
			}else{
				ans += arr[r].num;
				arr[l].num -= arr[r].num;
				r--;
			}
		}else if(arr[l].num == arr[r].num){
			if(arr[l].c == arr[r].c){
				l++;
				r--;
			}else{
				ans += arr[l].num;
				l++;
				r--;
			}
		}else{
			if(arr[l].c == arr[r].c){
				arr[r].num -= arr[l].num;
				l++;
			}else{
				ans += arr[l].num;
				arr[r].num -= arr[l].num;
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
