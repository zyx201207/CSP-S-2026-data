#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,a[N];
long long ans;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	int l = 1,r = n;
	while(l <= r){
		if(c[l] != c[r]){
			if(a[l] > a[r]){
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}else if(a[l] == a[r]){
				ans += a[l];
				a[r] = 0;
				a[l] = 0;
				l++;
				r--;
			}else{
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
		}else{
			if(a[l] > a[r]){
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}else if(a[l] == a[r]){
				a[r] = 0;
				a[l] = 0;
				l++;
				r--;
			}else{
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
		}
	}
	cout << ans;
	return 0;
} 
