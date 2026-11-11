#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],x;
int main(){
	freopen("andin","r",stdin);
	freopen("andout","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int j = n-1;j >= m-1;j--){
		x = a[j];
	}
	cout << x;
	return 0;
}	
