#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ma = 0;
	int an;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(m == 1){
			ma = max(ma, a[i]);
		}
		if(i == 0)an = a[i];
		else an &= a[i];
	}
	if(m == 1){
		cout << ma;
		return 0;
	}
	if(m == n){
		cout << an;
		return 0;
	}
	if(m == 2){
		int me = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j)continue;
				me = max(me, a[i] & a[j]);
			}
		}
		cout << me;
		return 0;
	}
	cout << 0;
	return 0;
}
