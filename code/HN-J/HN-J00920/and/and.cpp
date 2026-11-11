#include <bits/stdc++.h>

using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		int m,n;
	cin >> n >> m;
	int a[10000];
	for(int i;i<n;i++){
		cin >> a[i];
		
	}int b,b1;
	for (int i=0;i<n;i++){
		
		for(int j=0;j<n;j++){
			b1=a[i] & a[i+1];
			b=max(b,b1);
		}
	}
	cout << b;
	return 0;
}
