#include<bits/stdc++.h>
using namespace std;

long long n, l;
long long a[2000005], b[2000005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		char c;
		cin >> a[i] >> c;
		b[i] = c - 'a' + 1;
	}
	long long ans = 0;
	long long left=1, right=n;
	while(left < right){
		if(b[left] != b[right]){
			ans += min(a[left], a[right]);
		}
		if(a[left] > a[right]){
			a[left] -= a[right];
			right--;
		}else if(a[left] < a[right]){
			a[right] -= a[left];
			left++;
		}else if(a[left] == a[right]){
			right--;
			left++;
		}
	}
	cout << ans;
	return 0;
} 
