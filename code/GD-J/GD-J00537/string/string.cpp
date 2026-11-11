#include<bits/stdc++.h>
using namespace std;
string a;
long long n,ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int temp;
		char t;
		cin >> temp ;cin >> t;
		for(int j = 0; j < temp; j++) a +=t;
	}//aabbc
	long long l = 0,r = a.size() - 1;
	while(l < r){
		if(a[l] != a[r]) {
			ans++;
//			cout << a[l] << " " << a[r] << endl;
		}
		
		l++;r--;
	}
	cout << ans;
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

