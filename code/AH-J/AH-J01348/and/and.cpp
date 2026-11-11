#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, i, ans;
	cin>>n>>m;
	for(i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + 1 + n);
	if(m == 1){	
		cout<<a[n]<<endl;
		return 0;
	}
	if(m == n - 1){
		ans = a[2];
		for(i = 3; i <= n; i++) ans = ans & a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m == 2){
		ans = a[n - 1] & a[n];
		cout<<ans<<endl;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(i = 2; i <= n; i++)
		ans = ans & a[i];
		cout<<ans<<endl;
		return 0; 
	}
	return 0;
}
