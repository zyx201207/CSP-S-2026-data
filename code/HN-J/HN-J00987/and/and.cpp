#include <bits/stdc++.h>
using namespace std;
long long a[100000],n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >>a[i]; 
	}
	sort(a,a+n);
	ans = a[n-m];
	for(int i = m;i > 0;i--){
		ans = ans & a[n-m];
	} 
	cout << ans; 
	return 0; 
} 
