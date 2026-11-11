#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	} 
	if(n == 1){
		cout << 0;
		return 0;
	}
	bool f = 0;
	for(int i = 1;i < n;i++){
		if(c[i] == c[i - 1]) f = 1;
	}
	if(f){
		cout << 0;
		return 0;
	}
	cout << 1;
	return 0;
} 
