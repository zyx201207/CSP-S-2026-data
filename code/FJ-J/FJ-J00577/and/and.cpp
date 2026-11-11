#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	unsigned long long n, m, ans = 0;
	cin >> n >> m;
	unsigned long long a[n + 5];
	for(unsigned long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(unsigned long long i = 1; i < n; i++){
		if(a[i + 1] > a[i]){
			swap(a[i], a[i + 1]);
		}
	}
	for(unsigned long long i = 1; i <= m; i++){
		ans = a[i];
		ans = ans & a[i + 1];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
