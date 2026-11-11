#include<bits/stdc++.h>
using namespace std;

int n,m,a[200009],maxx = -12333;

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(m == 1){
			maxx = max(maxx,a[i]);
		}
	}
	if(m == 1){
		cout << maxx;
		return 0;
	}
	maxx = -12345;
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			int x = a[i]&a[j];
			maxx = max(x,maxx);
		}
	}
	cout << maxx;
	return 0;
} 
