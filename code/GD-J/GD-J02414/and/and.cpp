#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+5];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int s = 0;
	for(int j = 0;j < n;j++){
		int s2 = a[j];
		for(int k = 0;k < m;k++){
				s2 = s2 & a[(j + k) % n];
		}
		s = max(s,s2);
	}
	cout << s;
	return 0;
} 
