#include<bits/stdc++.h>
using namespace std;

long long n, a[200005][5], cnt; 

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(int i = 1; i <= n; i++) {
		char c;
		cin>>a[i][1]>>c;
		a[i][2] = c - 'a';
	}
	for(int i = 1, j = n; i <= j; ) {
		if(a[i][2] == a[j][2]) {
			if(a[i][1] > a[j][1]) {
				a[i][1] -= a[j][1];
				a[j][1] = 0;
				j--;
				continue;
			}
			if(a[i][1] < a[j][1]) {
				a[j][1] -= a[i][1];
				a[i][1] = 0;
				i++;
				continue;
			}
			if(a[i][1] == a[j][1]) {
				a[i][1] = a[j][1] = 0;
				i++;
				j--;
				continue;
			}
		} else {
			if(a[i][1] > a[j][1]) {
				cnt += a[j][1];
				a[i][1] -= a[j][1];
				a[j][1] = 0;
				j--;
				continue;
			}
			if(a[i][1] < a[j][1]) {
				cnt += a[i][1];
				a[j][1] -= a[i][1];
				a[i][1] = 0;
				i++;
				continue;
			}
			if(a[i][1] == a[j][1]) {
				cnt += a[i][1];
				a[i][1] = a[j][1] = 0;
				i++;
				j--;
				continue;
			}
		}
	}
	cout<<cnt<<"\n";
	
	return 0;
}
