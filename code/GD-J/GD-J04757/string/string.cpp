#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt, a[200003];
char c[200003];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int l = 1, r = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	while(l < r){
		if(c[l] != c[r]){
			if(a[l] > a[r]){
				cnt += a[r];
				a[l] -= a[r];
				r--;
			}else if(a[l] == a[r]){
				cnt += a[l];
				l++;
				r--;
			}else if(a[l] < a[r]){
				cnt += a[l];
				a[r] -= a[l];
				l++;
			}
		}else{
			if(a[l] > a[r]){
				a[l] -= a[r];
				r--;
			}else if(a[l] == a[r]){
				l++;
				r--;
			}else if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
}

