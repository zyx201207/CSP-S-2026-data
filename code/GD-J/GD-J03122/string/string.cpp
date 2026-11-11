#include <bits/stdc++.h>
using namespace std;
string a[100];
long long n,m[100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> m[i] >> a[i];
	}
	int r = 1;
	long long num = 0;
	for (int i = 1;i <= n/2;i++){
		if (m[i] == m[n-i+1] && a[i] != a[n-i+1]){
			r = 0;
			if(a[i] == a[n-i+1]){
				if (m[i] > m[n-i+1]) num += m[i]-m[n-i+1];
				else num += m[n-i+1]-m[i];
			}
			else {
				if (m[i] > m[n-i+1]) num += m[n-i+1];
				else num += m[i];
			}
		}
		
	}
	
	if (r == 1){
		num = 0;
	}
	if (n == 1){
		cout << 0;
		return 0;
	}
	if (n == 2){
		if (a[1] != a[2]){
			if (m[1] < m[2]){
				num = m[1];
			}
			else {
				num = m[2];
			}
		}
	}
	cout << num;
	return 0;
}
