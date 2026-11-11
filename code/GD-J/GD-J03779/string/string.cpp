#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("strint.out","w",stdout);
	long long n, a, x=0, ans=0;
	char c;
	char l[2070000];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> c;
		for(int j=0; j<a; j++){
			l[x] = c;
			x++;
		}
	}
	for(int i=0; i<x; i++){
		ans += (l[i]==l[x-1-i] ? 0 : 1);
	}
	cout << (int)(ans/2);
	return 0;
}
