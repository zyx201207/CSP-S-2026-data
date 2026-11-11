#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(i = 1,i <= n,i++){
		cin >> a[i];
	}
	int cnt = 0;
	if(a[i] == a[i-1]){
		cnt++;
	}
	cout << cnt;
	return 0;
}
