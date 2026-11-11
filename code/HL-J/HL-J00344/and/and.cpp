#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans[200005], ans1, cnt;
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1;i <= a[n];i+=pow(2, i)){
		if(lower_bound(a+1, a+n+1, i)-1-a-i<= lower_bound(a+1, a+n+1, i)-a-i){
			ans[i] = lower_bound(a+1, a+n+1, i)-1-a;
		}
		else{
			ans[i] = lower_bound(a+1, a+n+1, i)-a;
		}
	}
	for(int i = n;i >= 1;i--){
		if(ans[i]!=0){
			ans1 = ans[i];
			break;
		}
	}
	for(int i = n;i >= 1;i--){
		if(cnt ==m){
			break;
		}
		if(ans[i]!=0){
			ans1 = ans1&ans[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
