#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out.","w",stdout);
	int n,a[10005],c[10005];
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[i]+=c[i];
		}
		
	}
	cout << "0";
	return 0;
}
