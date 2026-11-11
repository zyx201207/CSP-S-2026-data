#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int n, sum, ans;
int a[N];
char c[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	
	int i = 1, j = n;
	while(true){
		if(a[i] == a[j]){
			if(c[i] != c[j]) ans += a[i];
			i ++;
			j --;
		}
		
		else if(a[i] > a[j]){
			if(c[i] != c[j]) ans += a[j];
			a[i] -= a[j];
			j --;
		}
		
		else{
			if(c[i] != c[j]) ans += a[i];
			a[j] -= a[i];
			i ++;
		}
		
		if(i >= j) break;
	}
	
	cout << ans;
	
	
	return 0;
}





