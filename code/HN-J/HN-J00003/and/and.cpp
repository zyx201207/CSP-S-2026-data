#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	int m, n;
	long long a[n+5];
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n-1; i++){
		long long s=a[i];
		if(a[i]>a[i+1]){
			a[i]=a[i+1];
			a[i+1]=s;
		}
	}
	cout << a[m-1];
	return 0;
}
