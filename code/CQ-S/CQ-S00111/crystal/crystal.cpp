#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans, num, m, a[N], sum, tot = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	num = 1;
	sort(a + 1, a + 1 + n);
	for(int i = 2; i <= n; i ++){
		while(sum + num * (a[i] - a[i - 1]) > m && tot < i){
			sum -= (a[i - 1] - a[tot ++]);
			num --;
		}
		if(sum + num * (a[i] - a[i - 1]) <= m){
			sum += num * (a[i] - a[i - 1]);
			num ++;
			ans = max(ans, num);
		} 
	}
	cout << ans;
	return 0;
} 
