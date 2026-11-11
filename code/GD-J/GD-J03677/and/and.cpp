#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	unsigned int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	sum=a[n-1];
	for(int i = n-2;i >=n-m;i--){
		sum=sum&a[i];
	}
	cout << sum;
	return 0;
}
