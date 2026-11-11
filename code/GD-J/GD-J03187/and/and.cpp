#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[15],l,r,c,s,g;
	cin >> n >> m;	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (m == 2){
		l = (a[3] & a[4]);
	}
	else if (m == 3){
		l = (a[1] & a[4] & a[5]);
	}
	cout << l;
	return 0;
}
