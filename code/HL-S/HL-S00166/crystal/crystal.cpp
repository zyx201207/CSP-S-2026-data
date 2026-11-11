#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,s = 0,a[N],c[N];
int main(){
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<n;i++){
		c[i] = a[i+1]-a[i];
	}
	for(int i = 1;i<n;i++){
		if(m - c[i] != 0){
			m -= c[i];
			s++;
		}
		if(m - c[i] == 0){
			m = 0;
			s++;
			break;
		}
	}
	cout << s;
	return 0;
}
