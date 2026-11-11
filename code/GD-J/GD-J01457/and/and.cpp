#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}sort (a+1,a+n+1);
	ans = a[n];
	if (m == 2){
		ans  = ans & a[n-1];
		cout<<ans;
	}else{
		for (int i  = n-1;i>=n-m+1;i--){
			ans = ans &a[i];
		}cout<<ans;
	}
	return 0;
} 
