#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[200010];
char crr[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
		scanf(" %c", &crr[i]);
	}
	long long ans = 0;
	int l = 1, r = n;
	while(l < r){
		if(arr[l] > arr[r]){
			if(crr[l] != crr[r]){
				ans += arr[r];
				arr[l] -= arr[r];
				r--;
			}
			else{
				arr[l] -= arr[r];
				r--;
			}
		}
		else if(arr[l] < arr[r]){
			if(crr[l] != crr[r]){
				ans += arr[l];
				arr[r] -= arr[l];
				l++;
			}
			else{
				arr[r] -= arr[l];
				l++;
			}
		}
		else if(arr[l] == arr[r]){
			if(crr[l] != crr[r]){
				ans += arr[l];
				l++;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
