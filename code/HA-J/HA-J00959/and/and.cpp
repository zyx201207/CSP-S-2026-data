#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
int a[N];
int main(){
	freopen("and.in","r", stdin);
	freopen("and.out","w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n; ++i){
		cin >> a[i];
	} 
	int b = 0, c = 1000000;
	for(int i = 1;i <= n; ++i){
		if(a[i] >= b){
			b = a[i];
	    }
	}
	if(m == 1){
		cout << b;
	}
}
